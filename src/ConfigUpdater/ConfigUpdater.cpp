/*
** EPITECH PROJECT, 2025
** test
** File description:
** ConfigUpdater
*/

#include "ConfigUpdater.hpp"
#include <print>

namespace Observer {
    ConfigUpdater::ConfigUpdater(const std::string &input_path, const std::string &output_path)
    {
        _input = std::make_shared<IPC::NamePipe>(input_path);
        _output = std::make_shared<IPC::NamePipe>(output_path);
    }

    ConfigUpdater::~ConfigUpdater()
    {
        if (_running)
            stop();
    }

    std::optional<std::string> ConfigUpdater::getConfig(void) const
    {
        return _output->read();
    }

    void ConfigUpdater::start(const std::string &config_path)
    {
        pid_t pid = 0;

        if (_running)
            throw ConfigUpdaterError("ConfigUpdater already running");

        _running = true;
        pid = fork();
        if (pid == -1) {
            throw ConfigUpdaterError("Failed to fork");
        } else if (pid == 0) {
            Observer::ConfigSubject subject(config_path, _input);
            Observer::ConfigObserver observer(subject, _output);
            subject.notifyObservers();
            std::println("Stoping observer: don't refresh config anymore");
            _exit(0);
        }
    }

    void ConfigUpdater::stop(void)
    {
        if (!_running)
            throw ConfigUpdaterError("ConfigUpdater not running");

        _input->write("finished");
        _running = false;
    }

    ConfigUpdater::ConfigUpdaterError::ConfigUpdaterError(const std::string &message) : _message(message)
    {}

    const char *ConfigUpdater::ConfigUpdaterError::what() const noexcept
    {
        return _message.c_str();
    }
}
