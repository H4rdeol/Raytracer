/*
** EPITECH PROJECT, 2025
** test
** File description:
** ConfigObserver
*/

#include "ConfigObserver.hpp"
#include <print>

namespace Observer {
    ConfigObserver::ConfigObserver(ASubject &subject, const std::shared_ptr<IPC::NamePipe> pipe)
    {
        subject.subscribe(*this);
        _pipe = pipe;
    }

    void ConfigObserver::update(const std::string &data)
    {
        try {
            _pipe->write(data);
        } catch (const IPC::NamePipe::PipeError &e) {
            std::println(std::cerr, "Error: {}", e.what());
        }
    }
}
