/*
** EPITECH PROJECT, 2025
** test
** File description:
** Camera
*/

#pragma once

#include <glm/glm.hpp>
#include <string>
#include <nlohmann/json.hpp>

namespace Application {
    class Camera {
        public:
            Camera() = default;
            ~Camera() = default;

            void update(const std::string &config);
        private:
            glm::vec2 _size;
            glm::vec3 _position;
            glm::vec3 _rotation;
            double _fov;
            glm::vec<4, unsigned int> _color;
    };
}
