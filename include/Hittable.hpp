/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** .hpp
*/

#pragma once

#include "Ray/Ray.hpp"

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
            virtual bool hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const = 0;
    };
}
