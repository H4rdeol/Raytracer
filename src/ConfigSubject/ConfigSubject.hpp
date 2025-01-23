/*
** EPITECH PROJECT, 2025
** test
** File description:
** ConfigSubject
*/

#pragma once

#include "ASubject.hpp"
#include "NamePipe/NamePipe.hpp"

#include <fstream>
#include <filesystem>
#include <optional>
#include <memory>
#include <thread>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class ConfigSubject: public ASubject {
    public:
        ConfigSubject(const std::string &path, NamePipe &pipe);
        ~ConfigSubject() final = default;

        class ConfigError : public std::exception {
            public:
                ConfigError(const std::string &message);
                const char *what() const noexcept override;
            private:
                std::string _message;
        };

        void notifyObservers(void) final;
    private:
        [[nodiscard]] bool _isFinished(void) const;
    private:
        std::string _path;
        std::shared_ptr<NamePipe> _pipe;
        json _root;
        std::filesystem::file_time_type _last_write_time;
};
