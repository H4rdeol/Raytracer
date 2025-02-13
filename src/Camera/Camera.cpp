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
    {
        std::ifstream file(path);
        std::ostringstream oss;

        if (!file.is_open())
            throw CameraException("Error config file not found");
        oss << file.rdbuf();
        file.close();
        auto data = nlohmann::json::parse(oss.str());

        setWithJson(data);
    }

    void Camera::update(const std::string &config)
    {
        auto data = nlohmann::json::parse(config);

        setWithJson(data);
        std::lock_guard<std::mutex> lock(_changedMutex);
        _changed = true;
    }

    void Camera::setWithJson(const nlohmann::basic_json<> &data)
    {
        auto size = data["camera"]["size"];
        auto position = data["camera"]["position"];
        auto rotation = data["camera"]["rotation"];
        auto color = data["camera"]["color"];

        _size = { size[0], size[1] };
        _position = { position[0], position[1], position[2] };
        _rotation = { rotation[0], rotation[1], rotation[2] };
        _fov = data["camera"]["fov"];
        Color tmp(color[0], color[1], color[2], (color.size() == 4) ?
            static_cast<std::uint8_t>(color[3]) :
            255
        );
        _color = tmp;
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

    Color Camera::getColor() const
    {
        return _color;
    }

    Camera::CameraException::CameraException(const std::string &message) :
        _message(message)
    {}

    const char *Camera::CameraException::what() const noexcept
    {
        return _message.c_str();
    }
} // namespace Application
