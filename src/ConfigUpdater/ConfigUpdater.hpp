/*
** EPITECH PROJECT, 2025
** test
** File description:
** ConfigUpdater
*/

#pragma once

#include "ConfigSubject/ConfigSubject.hpp"
#include "ConfigObserver/ConfigObserver.hpp"
#include "NamePipe/NamePipe.hpp"

namespace Observer {
    class ConfigUpdater {
        public:
            ConfigUpdater(const std::string &input_path = "/tmp/input", const std::string &output_path = "/tmp/output");
            ~ConfigUpdater();

            class ConfigUpdaterError : public std::exception {
                public:
                    ConfigUpdaterError(const std::string &message);
                    const char *what() const noexcept override;
                private:
                    std::string _message;
            };

            void start(const std::string &config_path);
            void stop(void);
        private:
            bool _running = false;
            std::shared_ptr<IPC::NamePipe> _input;
            std::shared_ptr<IPC::NamePipe> _output;
    };
}
