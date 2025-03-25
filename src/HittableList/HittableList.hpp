/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** HittableList.hpp
*/

#pragma once

#include "Hittable.hpp"

#include <vector>
#include <memory>

namespace Raytracer {
    class HittableList: public Hittable {
        public:
            HittableList() = default;
            ~HittableList() = default;

            void clear();
            void add(std::shared_ptr<Hittable> object);
            bool hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const override;
        private:
            std::vector<std::shared_ptr<Hittable>> _objects;
    };
} // namespace Raytracer
