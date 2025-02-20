/*
** EPITECH PROJECT, 2025
** test
** File description:
** Camera
*/

#pragma once

#include "Image/Image.hpp"

#include <exception>
#include <glm/glm.hpp>
#include <mutex>
#include <string>
#include <nlohmann/json.hpp>

namespace Application {
    class Camera {
        public:
            explicit Camera(const std::string &path);
            ~Camera() = default;

            class CameraException final : public std::exception {
                public:
                    explicit CameraException(const std::string &message);
                    [[nodiscard]] const char *what() const noexcept override;
                private:
                    std::string _message;
            };

            void update(const std::string &config);
            [[nodiscard]] glm::vec<2, unsigned int> getSize() const;
            [[nodiscard]] glm::vec3 getPosition() const;
            [[nodiscard]] glm::vec3 getRotation() const;
            [[nodiscard]] double getFov() const;
            [[nodiscard]] Image getImage() const;
            void setWithJson(const nlohmann::basic_json<> &data);
        private:
            bool _changed = false;
            std::mutex _changedMutex;
            glm::vec<2, unsigned int> _size;
            glm::vec3 _position;
            glm::vec3 _rotation;
            double _fov;
            Image _image;
    };
}
