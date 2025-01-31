/*
** EPITECH PROJECT, 2025
** test
** File description:
** Camera
*/

#pragma once

#include <glm/glm.hpp>
#include <string>

namespace Application {
    class Camera {
        public:
            Camera();
            ~Camera();

            void update(const std::string &config);
        private:
            glm::vec2 _size;
            glm::vec3 _position;
            glm::vec3 _rotation;
            double _fov;
            glm::vec3 _color;
    };
}
