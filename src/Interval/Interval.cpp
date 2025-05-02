/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Interval.cpp
*/

#include "Interval.hpp"
#include "Maths/Vec3.hpp"

namespace Maths {
    const Interval Interval::empty = Interval();
    const Interval Interval::universe = Interval(-infinity, +infinity);

    Interval::Interval() : max(-infinity), min(+infinity) {}

    Interval::Interval(double min, double max) : max(max), min(min) {}

    double Interval::size() const
    {
        return max - min;
    }

    double Interval::clamp(const double x) const
    {
        return (x < min) ? min : (x > max) ? max : x;
    }

    bool Interval::contains(const double x) const
    {
        return min <= x && x <= max;
    }

    bool Interval::surrounds(const double x) const
    {
        return min < x && x < max;
    }
}
