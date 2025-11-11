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
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <memory>

namespace Application {
    Application::Application(const std::string &path)
        : camera(std::make_unique<Camera>(path)), _windowSize(this->camera->getSize()),
          _texture({_windowSize.x, _windowSize.y}), _sprite(_texture)
    {
        _window.create(
            sf::VideoMode({_windowSize.x, _windowSize.y}, _bitPerPixels),
            "Raytracer",
            sf::Style::Close
        );
        sf::Vector2u screenCenter = sf::VideoMode::getDesktopMode().size / 2u;
        _window.setPosition({
            static_cast<int>(screenCenter.x - _windowSize.x / 2u),
            static_cast<int>(screenCenter.y - _windowSize.y / 2u)
        });
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
    }

    void Application::_convertImage()
    {
        const std::vector<Color> pixels = camera->getImage().getPixels();
        std::vector<std::uint8_t> pixelsConverted;

        for (const auto &pixel : pixels) {
            pixelsConverted.push_back(pixel.red());
            pixelsConverted.push_back(pixel.green());
            pixelsConverted.push_back(pixel.blue());
            pixelsConverted.push_back(pixel.alpha());
        }
        _texture.update(pixelsConverted.data());
    }

    void Application::run()
    {
        sf::Clock clock;
        bool renderLaunched = false;

        clock.start();
        while (_window.isOpen()) {
            _window.clear(sf::Color::White);
            while (const auto event = _window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    _window.close();
                    _isRunning = false;
                    continue;
                }
                if (event->is<sf::Event::KeyPressed>()) {
                    const sf::Event::KeyPressed *evt = event.value().getIf<sf::Event::KeyPressed>();
                    if (evt->code == sf::Keyboard::Key::A && !renderLaunched) {
                        camera->render();
                    }
                }
            }
            _convertImage();
            _window.draw(_sprite);
            if (clock.getElapsedTime().asSeconds() >= 1.0) {
                refreshConfig();
                clock.restart();
            }
            _window.display();
        }
    }

    bool Application::isRunning() const
    {
        return _isRunning;
    }
}
