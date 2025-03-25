/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** HittableList.cpp
*/

#include "HittableList.hpp"

namespace Raytracer {
    void HittableList::clear()
    {
        _objects.clear();
    }

    void HittableList::add(std::shared_ptr<Hittable> object)
    {
        _objects.push_back(object);
    }

    bool HittableList::hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const
    {
        HitRecord temp_rec;
        bool hit_anything = false;
        double closest_so_far = t_max;

        for (const auto &object : _objects) {
            if (object->hit(r, t_min, closest_so_far, temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }
        return hit_anything;
    }
} // namespace Raytracer
