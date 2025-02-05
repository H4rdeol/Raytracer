/*
** EPITECH PROJECT, 2025
** test
** File description:
** Camera
*/

#pragma once

#include "Colors/Colors.hpp"

#include <exception>
#include <glm/glm.hpp>
#include <mutex>
#include <string>
#include <nlohmann/json.hpp>

namespace Application {
    class Camera {
        public:
            Camera(const std::string &path);
            ~Camera() = default;

            class CameraException: public std::exception {
                public:
                    CameraException(const std::string &message);
                    const char *what() const noexcept override;
                private:
                    std::string _message;
            };

            void update(const std::string &config);
            [[nodiscard]] glm::vec<2, unsigned int> getSize() const;
            [[nodiscard]] glm::vec3 getPosition() const;
            [[nodiscard]] glm::vec3 getRotation() const;
            [[nodiscard]] double getFov() const;
            [[nodiscard]] Color getColor() const;
            void setWithJson(const nlohmann::basic_json<> &data);
        private:
            bool _changed = false;
            std::mutex _changedMutex;
            glm::vec<2, unsigned int> _size;
            glm::vec3 _position;
            glm::vec3 _rotation;
            double _fov;
            Color _color;
    };
}
