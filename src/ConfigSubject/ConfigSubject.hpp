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

namespace Observer {
    class ConfigSubject: public ASubject {
        public:
            ConfigSubject(const std::string &path, const std::shared_ptr<IPC::NamePipe> pipe);
            ~ConfigSubject() final = default;
    
            class ConfigError : public std::exception {
                public:
                    ConfigError(const std::string &message);
                    const char *what() const noexcept override;
                private:
                    std::string _message;
            };
    
            void notifyObservers(void) final;
            void setRefreshRate(const std::size_t rate);
        private:
            [[nodiscard]] bool _isFinished(void) const;
        private:
            std::string _path;
            std::shared_ptr<IPC::NamePipe> _input;
            json _root;
            std::filesystem::file_time_type _last_write_time;
            std::size_t _refresh_rate = 1000;
    };
}
