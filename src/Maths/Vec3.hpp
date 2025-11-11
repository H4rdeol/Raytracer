/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Vec3.hpp
*/

#pragma once

#include <glm/geometric.hpp>
#include <glm/glm.hpp>
#include <random>

glm::vec<3, double> operator*(const std::size_t lhs, const glm::vec<3, double> & vec);
glm::vec<3, double> operator+(const glm::vec<3, double> & vec, const std::size_t rhs);
glm::vec<3, double> operator*(const double lhs, const glm::vec<3, double> & vec);
glm::vec<3, double> randomVector();
glm::vec<3, double> randomVector(double min, double max);

using point3 = glm::vec<3, double>;

namespace Maths {
    double degrees_to_radians(double degrees);

    constexpr inline double randomDouble()
    {
        static std::uniform_real_distribution<double> distribution(0.0, 1.0);
        static std::mt19937 generator;

        return distribution(generator);
    }

    constexpr inline double randomDouble(double min, double max)
    {
        return min + (max - min) * randomDouble();
    }

    constexpr inline double linearToGamma(double linearComponent)
    {
        if (linearComponent > 0)
            return std::sqrt(linearComponent);
        return 0;
    }

    constexpr double infinity = std::numeric_limits<double>::infinity();

    constexpr inline glm::vec<3, double> randomUnitVector()
    {
        while (true) {
            const auto p = randomVector(-1, 1);
            const auto lensq = glm::length(p) * glm::length(p);

            if (1e-160 < lensq && lensq <= 1)
                return p / std::sqrt(lensq);
        }
    }

    constexpr inline glm::vec<3, double> randomOnHemisphere(const glm::vec<3, double> &normal)
    {
        const glm::vec<3, double> onUnitSphere = randomUnitVector();
        
        if (glm::dot(onUnitSphere, normal) > 0.0)
            return onUnitSphere;
        return -onUnitSphere;
    }
}
