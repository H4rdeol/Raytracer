/*
** EPITECH PROJECT, 2025
** test
** File description:
** ConfigSubject
*/

#include "ConfigSubject.hpp"

ConfigSubject::ConfigSubject(const std::string &path, NamePipe &pipe) : _path(path)
{
    _pipe = std::make_shared<NamePipe>(pipe);
    _last_write_time = std::filesystem::file_time_type::min();
}

bool ConfigSubject::_isFinished(void) const
{
    std::optional<std::string> data = _pipe->read();

    if (!data)
        return false;
    return data.value() == "finished";
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
        }
    } while (true);
}

ConfigSubject::ConfigError::ConfigError(const std::string &message) : _message(message)
{}

const char *ConfigSubject::ConfigError::what() const noexcept
{
    return _message.c_str();
}
