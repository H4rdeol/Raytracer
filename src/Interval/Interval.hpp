/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Interval.hpp
*/

#pragma once

namespace Maths {
    class Interval {
        public:
            Interval();
            Interval(double min, double max);
            [[nodiscard]] double size() const;
            [[nodiscard]] bool contains(const double x) const;
            [[nodiscard]] bool surrounds(const double x) const;
            [[nodiscard]] double clamp(const double x) const;

            static const Interval empty, universe;
            double max;
            double min;
    };
}
