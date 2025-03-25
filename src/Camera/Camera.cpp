/*
** EPITECH PROJECT, 2025
** test
** File description:
** Camera
*/

#include "Camera.hpp"
#include "Maths/Vec3.hpp"
#include "Sphere/Sphere.hpp"
#include "HittableList/HittableList.hpp"

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
        _initializeValues();

        Raytracer::HittableList world;
        world.add(std::make_shared<Raytracer::Sphere>(point3(0, 0, -1), 0.5));
        world.add(std::make_shared<Raytracer::Sphere>(point3(0, -100.5, -1), 100));

        //TEST

        for (std::size_t j = 0; j < _size.y; j++) {
            for (std::size_t i = 0; i < _size.x; i++) {
                auto pixel_center = _pixel00_loc + (i * _pixel_delta_u) + (j * _pixel_delta_v);
                auto ray_direction = pixel_center - _camera_center;
                Raytracer::Ray r(_camera_center, ray_direction);

                _image.updatePixel(Raytracer::Ray::rayColor(r, world), i, j);
            }
        }
        //TEST
    }

    point3 operator/(const point3 &vec, const double rhs)
    {
        return {vec.x / rhs, vec.y / rhs, vec.z / rhs};
    }

    void Camera::_initializeValues()
    {
        constexpr double focal_length = 1.0;
        constexpr double viewport_height = 2.0;
        const double viewport_width = viewport_height * (static_cast<double>(_size.x) / _size.y);

        const auto viewport_u = glm::vec<3, double>(viewport_width, 0, 0);
        constexpr auto viewport_v = glm::vec<3, double>(0, -viewport_height, 0);

        _pixel_delta_u = viewport_u / _size.x;
        _pixel_delta_v = viewport_v / _size.y;

        const auto viewport_upper_left =
            _camera_center - glm::vec<3, double>(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
        _pixel00_loc = viewport_upper_left + 0.5 * (_pixel_delta_u + _pixel_delta_v);
    }

    void Camera::update(const std::string &config)
    {
        const auto data = nlohmann::json::parse(config);

        setWithJson(data);
        std::lock_guard lock(_changedMutex);
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
