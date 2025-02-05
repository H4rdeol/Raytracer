/*
** EPITECH PROJECT, 2025
** test
** File description:
** Application
*/

#include "Application.hpp"
#include "Camera/Camera.hpp"
#include "Colors/Colors.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <memory>

namespace Application {
    Application::Application(const std::string &path) :
        camera(std::make_unique<Camera>(path))
    {
        _windowSize = this->camera->getSize();
        _window.create(
            sf::VideoMode({ _windowSize.x, _windowSize.y }, _bitPerPixels),
            "Raytracer"
        );
        _backGroundColor = sf::Color(this->camera->getColor().getColorInt());
    }

    void Application::refreshConfig()
    {
        if (this->camera->getSize().x != _windowSize.x || this->camera->getSize().y != _windowSize.y) {
            _window.close();
            _window.create(
                sf::VideoMode({ this->camera->getSize().x, this->camera->getSize().y }, _bitPerPixels),
                "Raytracer"
            );
            _windowSize = this->camera->getSize();
        }
        _backGroundColor = sf::Color(this->camera->getColor().getColorInt());
    }

    void Application::run()
    {
        sf::Clock clock;

        clock.start();
        while (_window.isOpen()) {
            _window.clear(_backGroundColor);
            while (auto event = _window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    _window.close();
                    _isRunning = false;
                }
            }
            _window.display();
            if (clock.getElapsedTime().asSeconds() >= 1.0) {
                refreshConfig();
                clock.restart();
            }
        }
    }

    bool Application::isRunning() const
    {
        return _isRunning;
    }
}
