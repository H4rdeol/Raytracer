/*
** EPITECH PROJECT, 2025
** my_project
** File description:
** Ray.cpp
**
*/

#include "Ray.hpp"
#include "Interval/Interval.hpp"
#include "Maths/Vec3.hpp"

#include <cmath>
#include <glm/detail/qualifier.hpp>
#include <glm/geometric.hpp>

namespace Raytracer {
    Ray::Ray(const point3 &origin, const point3 &direction)
        : _origin(origin), _direction(direction)
    {
    }

    const point3 &Ray::getOrigin() const
    {
        return _origin;
    }

    const glm::vec<3, double> &Ray::getDirection() const
    {
        return _direction;
    }

    point3 Ray::at(double t) const
    {
        return _origin + _direction * t;
    }

    double Ray::_hitSphere(const point3 &center, double radius, const Ray &r)
    {
        glm::vec<3, double> oc = center - r.getOrigin();
        const double a = r._direction.x * r._direction.x + r._direction.y * r._direction.y + r._direction.z * r._direction.z;
        const double h = glm::dot(r._direction, oc);
        const double c = oc.x * oc.x + oc.y * oc.y + oc.z * oc.z - radius * radius;
        const double discriminant = h * h - a * c;

        if (discriminant < 0)
            return -1.0;
        return (h - sqrt(discriminant)) / a;
    }

    glm::vec3 Ray::rayColor(const Ray &r, const Hittable &world)
    {
        HitRecord rec;
        static const Maths::Interval intensity(0.000, 0.999);

        if (world.hit(r, Maths::Interval(0, Maths::infinity), rec)) {
            const glm::vec3 color = 0.5 * (rec.normal + glm::vec3(1, 1, 1));
            return color;
        }
        glm::vec3 unit_direction = glm::normalize(r.getDirection());
        const double a = 0.5 * (unit_direction.y + 1.0);
        const glm::vec3 color = (1.0 - a) * glm::vec3(1.0, 1.0, 1.0) + a * glm::vec3(0.5, 0.7, 1.0);

        return color;
    }
} // Raytracer
