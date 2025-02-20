/*
** EPITECH PROJECT, 2025
** my_project
** File description:
** Ray.cpp
**
*/

#include "Ray.hpp"

#include <iostream>

namespace Raytracer {

    glm::vec<3, double> operator*(const double lhs, const glm::vec<3, double> & vec)
    {
        return {vec.x * lhs, vec.y * lhs, vec.z * lhs};
    }

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

    Application::Color Ray::rayColor(const Ray &r)
    {
        glm::vec3 unit_direction = glm::normalize(r.getDirection());
        const double a = 0.5 * (unit_direction.y + 1.0);
        const glm::vec3 color = (1.0 - a) * glm::vec3(1.0, 1.0, 1.0) + a * glm::vec3(0.5, 0.7, 1.0);

        return Application::Color(color.x * 255.999, color.y * 255.999, color.z * 255.999);
    }
} // Raytracer