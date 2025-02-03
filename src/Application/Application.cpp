/*
** EPITECH PROJECT, 2025
** test
** File description:
** Application
*/

#include "Application.hpp"
#include "Camera/Camera.hpp"
#include <memory>

namespace Application {
    Application::Application(const Camera &camera) :
        camera(std::make_unique<Camera>(camera))
    {
        _window.setSize({ this->camera->getSize().x, this->camera->getSize().y });
    }

    bool Application::isRunning() const
    {
        return _isRunning;
    }
}
