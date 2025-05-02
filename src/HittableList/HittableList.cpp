/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** HittableList.cpp
*/

#include "HittableList.hpp"
#include "Interval/Interval.hpp"

namespace Raytracer {
    void HittableList::clear()
    {
        _objects.clear();
    }

    void HittableList::add(std::shared_ptr<Hittable> object)
    {
        _objects.push_back(object);
    }

    bool HittableList::hit(const Ray &r, Maths::Interval ray_t, HitRecord &rec) const
    {
        HitRecord temp_rec;
        bool hit_anything = false;
        double closest_so_far = ray_t.max;

        for (const auto &object : _objects) {
            if (object->hit(r, Maths::Interval(ray_t.min, closest_so_far), temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }
        return hit_anything;
    }
} // namespace Raytracer
