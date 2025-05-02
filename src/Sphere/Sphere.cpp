/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

#include <cmath>
#include <glm/glm.hpp>

namespace Raytracer {
    Sphere::Sphere(const point3 &center, double radius) : _center(center), _radius(std::fmax(0, radius)) {}

    bool Sphere::hit(const Ray &r, Maths::Interval ray_t, HitRecord &rec) const
    {
        glm::vec<3, double> oc = _center - r.getOrigin();
        double a = pow(glm::length(r.getDirection()), 2);
        double h = glm::dot(r.getDirection(), oc);
        double c = pow(glm::length(oc), 2) - _radius * _radius;
        double discriminant = h * h - a * c;

        if (discriminant < 0)
            return false;
        double sqrtd = std::sqrt(discriminant);
        double root = (h - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }
        rec.t = root;
        rec.p = r.at(rec.t);
        glm::vec<3, double> outward_normal = (rec.p - _center) / _radius;
        rec.setFaceNormal(r, outward_normal);
        return true;
    }
} // namespace Raytracer
