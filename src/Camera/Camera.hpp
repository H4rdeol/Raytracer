/*
** EPITECH PROJECT, 2025
** test
** File description:
** Camera
*/

#pragma once

#include <cstdint>
#include <exception>
#include <glm/glm.hpp>
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
            [[nodiscard]] glm::vec<4, uint8_t> getColor() const;
            void setWithJson(const nlohmann::basic_json<> &data);
        private:
            bool _changed = false;
            glm::vec<2, unsigned int> _size;
            glm::vec3 _position;
            glm::vec3 _rotation;
            double _fov;
            glm::vec<4, uint8_t> _color;
    };
}
