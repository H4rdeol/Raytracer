/*
** EPITECH PROJECT, 2025
** test
** File description:
** NamePipe
*/

#pragma once

#include <string>
#include <exception>
#include <optional>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <iostream>

namespace IPC {
    class NamePipe {
        public:
            NamePipe(const std::string &path = "/tmp/namepipe");
            ~NamePipe();
    
            class PipeError : public std::exception {
                public:
                    PipeError(const std::string &message);
                    const char *what() const noexcept override;
                private:
                    std::string _message;
            };
    
            void write(const std::string &data) const;
            [[nodiscard]] std::optional<std::string> read(void) const;
        public:
            static constexpr size_t BUFFER_SIZE = 1024;
        private:
            const std::string _path;
            int _fd;
    };
}
