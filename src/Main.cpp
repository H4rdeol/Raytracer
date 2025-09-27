/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Main
*/

#include <thread>
#include <print>
#include "Application/Application.hpp"
#include "ConfigUpdater/ConfigUpdater.hpp"

int main()
{
    Application::Application app("assets/configs/test.cfg");

    std::jthread observer_thread(
        [](const Application::Application &appl) {
            Observer::ConfigUpdater updater;

            updater.start("assets/configs/test.cfg");
            while (appl.isRunning()) {
                if (auto config = updater.getConfig())
                    appl.camera->update(config.value());
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
            updater.stop();
        },
        std::ref(app)
    );

	std::println("Press A to start the renderer");
    app.run();
    observer_thread.join();
    return 0;
}
