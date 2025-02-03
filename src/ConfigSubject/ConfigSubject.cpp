/*
** EPITECH PROJECT, 2025
** test
** File description:
** ConfigSubject
*/

#include "ConfigSubject.hpp"
#include <thread>
#include <fstream>

namespace Observer {
    ConfigSubject::ConfigSubject(const std::string &path, const std::shared_ptr<IPC::NamePipe> pipe) : _path(path)
    {
        _input = pipe;
        _last_write_time = std::filesystem::file_time_type::min();
    }

    bool ConfigSubject::_isFinished(void) const
    {
        std::optional<std::string> data = _input->read();

        if (!data)
            return false;
        return data.value() == "finished";
    }

    void ConfigSubject::setRefreshRate(const std::size_t rate)
    {
        _refresh_rate = rate;
    }

    void ConfigSubject::notifyObservers()
    {
        do {
            auto timestamp = std::filesystem::last_write_time(_path);

            if (_last_write_time != timestamp) {
                std::ifstream file(_path);
                std::ostringstream oss;

                if (file.peek() == std::ifstream::traits_type::eof())
                    continue;
                oss << file.rdbuf();
                file.close();
                _root = json::parse(oss.str());
                _last_write_time = timestamp;

                for (auto &observer : _list_observers)
                    observer->update(_root.dump());
                std::this_thread::sleep_for(std::chrono::milliseconds(_refresh_rate));
            }
        } while (!_isFinished());
    }

    ConfigSubject::ConfigError::ConfigError(const std::string &message) : _message(message)
    {}

    const char *ConfigSubject::ConfigError::what() const noexcept
    {
        return _message.c_str();
    }
}
