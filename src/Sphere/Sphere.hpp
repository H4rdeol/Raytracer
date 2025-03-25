/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Sphere.hpp
*/

#pragma once

#include "Hittable.hpp"

namespace Raytracer {
    class Sphere: public Hittable {
        public:
            Sphere(const point3 &center, double radius);
            ~Sphere() = default;

            bool hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const override;
        private:
            point3 _center;
            double _radius;
    };
} // namespace Raytracer
