/*
** EPITECH PROJECT, 2025
** test
** File description:
** Camera
*/

#pragma once

#include "HittableList/HittableList.hpp"
#include "Maths/Vec3.hpp"
#include "Image/Image.hpp"
#include "Ray/Ray.hpp"

#include <exception>
#include <string>
#include <nlohmann/json.hpp>
#include <thread>
#include <vector>

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
            void render();
        private:
            void _initializeValues();
            Raytracer::Ray _getRay(int i, int j) const;
            glm::vec3 _sampleSquare() const;
        private:
            const size_t _nbThreads = std::thread::hardware_concurrency();
            std::vector<std::jthread> _threads;
            unsigned int _sample_per_pixel = 10;
            double _pixel_samples_scale;
            glm::vec<2, unsigned int> _size;
            glm::vec3 _position;
            glm::vec3 _rotation;
            double _fov;
            Image _image;
            point3 _camera_center = point3(0, 0, 0);
            glm::vec<3, double> _pixel_delta_u;
            glm::vec<3, double> _pixel_delta_v;
            glm::vec<3, double> _pixel00_loc;
            Raytracer::HittableList _world;
    };
}
