/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Vec3.hpp
*/

#pragma once

#include <glm/glm.hpp>

glm::vec<3, double> operator*(const std::size_t lhs, const glm::vec<3, double> & vec);
glm::vec<3, double> operator+(const glm::vec<3, double> & vec, const std::size_t rhs);
glm::vec<3, double> operator*(const double lhs, const glm::vec<3, double> & vec);

using point3 = glm::vec<3, double>;

namespace Maths {
    double degrees_to_radians(double degrees);
    constexpr double infinity = std::numeric_limits<double>::infinity();
}
