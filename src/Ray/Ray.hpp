/*
** EPITECH PROJECT, 2025
** my_project
** File description:
** Ray.hpp
**
*/

#pragma once

#include "Maths/Vec3.hpp"
#include "Colors/Colors.hpp"
#include "Hittable.hpp"

namespace Raytracer {
    class Hittable;

    class Ray {
        public:
            Ray() = default;
            Ray(const point3 &origin, const point3 &direction);
            ~Ray() = default;

            [[nodiscard]] const point3 &getOrigin() const;
            [[nodiscard]] const glm::vec<3, double> &getDirection() const;
            [[nodiscard]] point3 at(double t) const;

            static Application::Color rayColor(const Ray &r, const Hittable &world);
        private:
            static double _hitSphere(const point3 &center, double radius, const Ray &r);
            point3 _origin;
            glm::vec<3, double> _direction;

    };

} // Raytracer
