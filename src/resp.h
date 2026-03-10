#pragma once

#include <string>
#include <vector>
#include <optional>

struct Command {
    std::string name;
    std::vector<std::string> args;
};

std::optional<Command> parseCommand(const std::string& data);