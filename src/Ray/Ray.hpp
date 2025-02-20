/*
** EPITECH PROJECT, 2025
** my_project
** File description:
** Ray.hpp
**
*/

#pragma once

#include <glm/glm.hpp>

#include "Colors/Colors.hpp"

using point3 = glm::vec<3, double>;

namespace Raytracer {
    class Ray {
        public:
            Ray() = default;
            Ray(const point3 &origin, const point3 &direction);
            ~Ray() = default;

            [[nodiscard]] const point3 &getOrigin() const;
            [[nodiscard]] const glm::vec<3, double> &getDirection() const;
            [[nodiscard]] point3 at(double t) const;

            static Application::Color rayColor(const Ray &r);
        private:
            point3 _origin;
            glm::vec<3, double> _direction;

    };

} // Raytracer
