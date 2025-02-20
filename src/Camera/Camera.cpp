/*
** EPITECH PROJECT, 2025
** test
** File description:
** Camera
*/

#include "Camera.hpp"
#include "Colors/Colors.hpp"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <mutex>
#include <nlohmann/json.hpp>

namespace Application {
    Camera::Camera(const std::string &path)
        : _image(0, 0)
    {
        std::ifstream file(path);
        std::ostringstream oss;

        if (!file.is_open())
            throw CameraException("Error config file not found");
        oss << file.rdbuf();
        file.close();
        auto data = nlohmann::json::parse(oss.str());

        setWithJson(data);
        _image = Image(_size.x, _size.y);

        //TEST

        for (std::size_t j = 0; j < _size.y; j++) {
            for (std::size_t i = 0; i < _size.x; i++) {
                auto r = static_cast<double>(i) / (_size.x-1);
                auto g = static_cast<double>(j) / (_size.y-1);
                auto b = 0.0;

                int ir = static_cast<int>(255.999 * r);
                int ig = static_cast<int>(255.999 * g);
                int ib = static_cast<int>(255.999 * b);

                _image.updatePixel(Color(ir, ig, ib), i, j);
            }
        }

        //TEST
    }

    void Camera::update(const std::string &config)
    {
        const auto data = nlohmann::json::parse(config);

        setWithJson(data);
        std::lock_guard<std::mutex> lock(_changedMutex);
        _changed = true;
    }

    void Camera::setWithJson(const nlohmann::basic_json<> &data)
    {
        auto size = data["camera"]["size"];
        auto position = data["camera"]["position"];
        auto rotation = data["camera"]["rotation"];

        _size = { size[0], size[1] };
        _position = { position[0], position[1], position[2] };
        _rotation = { rotation[0], rotation[1], rotation[2] };
        _fov = data["camera"]["fov"];
    }

    glm::vec<2, unsigned int> Camera::getSize() const
    {
        return _size;
    }

    glm::vec3 Camera::getPosition() const
    {
        return _position;
    }

    glm::vec3 Camera::getRotation() const
    {
        return _rotation;
    }

    double Camera::getFov() const
    {
        return _fov;
    }

    Image Camera::getImage() const
    {
        return _image;
    }

    Camera::CameraException::CameraException(const std::string &message) :
        _message(message)
    {}

    const char *Camera::CameraException::what() const noexcept
    {
        return _message.c_str();
    }
} // namespace Application
