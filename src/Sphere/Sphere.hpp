/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Sphere.hpp
*/

#pragma once

#include "Hittable.hpp"
#include "Interval/Interval.hpp"

namespace Raytracer {
    class Sphere final: public Hittable {
        public:
            Sphere(const point3 &center, double radius);
            ~Sphere() = default;

            bool hit(const Ray &r, Maths::Interval ray_t, HitRecord &rec) const override;
        private:
            point3 _center;
            double _radius;
    };
} // namespace Raytracer
