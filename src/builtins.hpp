#pragma once
#include "myshell.hpp"
#include <unordered_map>
#include <functional>


sh_status_t echo(std::stringstream& args);

sh_status_t type(std::stringstream& args);

sh_status_t shell_exit(std::stringstream& args);

extern const std::unordered_map<std::string, std::function<sh_status_t(std::stringstream&)>> BUILTIN_COMMANDS;
