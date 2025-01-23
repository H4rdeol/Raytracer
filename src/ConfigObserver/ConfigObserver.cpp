/*
** EPITECH PROJECT, 2025
** test
** File description:
** ConfigObserver
*/

#include "ConfigObserver.hpp"

ConfigObserver::ConfigObserver(ASubject &subject, NamePipe &pipe)
{
    subject.subscribe(*this);
    _pipe = std::make_shared<NamePipe>(pipe);
}

void ConfigObserver::update(const std::string &data)
{
    try {
        _pipe->write(data);
    } catch (const NamePipe::PipeError &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
