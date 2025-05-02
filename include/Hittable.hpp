/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** .hpp
*/

#pragma once

#include "Ray/Ray.hpp"
#include "Interval/Interval.hpp"

namespace Raytracer {
    class Ray;
    struct HitRecord {
        point3 p;
        glm::vec3 normal;
        double t;
        bool front_face;

        void setFaceNormal(const Ray &r, const glm::vec<3, double> &outward_normal);
    };

    class Hittable {
        public:
            virtual bool hit(const Ray &r, Maths::Interval ray_t, HitRecord &rec) const = 0;
    };
}
