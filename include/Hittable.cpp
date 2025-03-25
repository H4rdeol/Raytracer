/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Hittable.cpp
*/

#include "Hittable.hpp"

void Raytracer::HitRecord::setFaceNormal(const Ray &r, const glm::vec<3, double> &outward_normal) {
    front_face = glm::dot(r.getDirection(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
}
