/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Main
*/

#include <thread>
#include "Application/Application.hpp"
#include "ConfigUpdater/ConfigUpdater.hpp"

//TODO: @LO change cmake to find new .cpp
int main(void)
{
    Application::Application app("assets/configs/test.cfg");

    std::jthread observer_thread(
        [](const Application::Application &app) {
            Observer::ConfigUpdater updater;

            updater.start("assets/configs/test.cfg");
            while (app.isRunning()) {
                if (auto config = updater.getConfig())
                    app.camera->update(config.value());
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
            updater.stop();
        },
        std::ref(app)
    );

    app.run();
    observer_thread.join();
    return 0;
}
