/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Vec3.cpp
*/

#include "Vec3.hpp"
#include <numbers>

glm::vec<3, double> operator*(const std::size_t lhs, const glm::vec<3, double> & vec)
{
    return {vec.x * lhs, vec.y * lhs, vec.z * lhs};
}

glm::vec<3, double> operator+(const glm::vec<3, double> & vec, const std::size_t rhs)
{
    return {vec.x + rhs, vec.y + rhs, vec.z + rhs};
}

glm::vec<3, double> operator*(const double lhs, const glm::vec<3, double> & vec)
{
    return {vec.x * lhs, vec.y * lhs, vec.z * lhs};
}

double degrees_to_radians(double degrees)
{
    return degrees * std::numbers::pi / 180.0;
}
