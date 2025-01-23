/*
** EPITECH PROJECT, 2025
** test
** File description:
** NamePipe
*/

#include "NamePipe.hpp"

NamePipe::NamePipe(const std::string &path) : _path(path)
{
    if (access(_path.c_str(), F_OK) == -1) {
        if (mkfifo(_path.c_str(), 0666) == -1) {
            throw PipeError("Failed to create pipe");
        }
    }
    _fd = open(_path.c_str(), O_RDWR);
    if (_fd == -1) {
        throw PipeError("Failed to open pipe");
    }
}

NamePipe::~NamePipe()
{
    close(_fd);
}

void NamePipe::write(const std::string &data) const
{
    if (::write(_fd, data.c_str(), data.size()) == -1) {
        throw PipeError("Failed to write to pipe");
    }
}

std::optional<std::string> NamePipe::read(void) const
{
    char buffer[BUFFER_SIZE] = {0};
    int bytes = 0;
    std::string data;
    fd_set readfds;
    struct timeval tv;

    FD_ZERO(&readfds);
    FD_SET(_fd, &readfds);
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    if (select(_fd + 1, &readfds, nullptr, nullptr, &tv) <= 0)
        return std::nullopt;
    while ((bytes = ::read(_fd, buffer, sizeof(buffer))) > 0) {
        data += std::string(buffer, bytes);
        if (static_cast<size_t>(bytes) < BUFFER_SIZE)
            break;
    }
    return data;
}

NamePipe::PipeError::PipeError(const std::string &message) : _message(message)
{}

const char *NamePipe::PipeError::what() const noexcept
{
    return _message.c_str();
}
