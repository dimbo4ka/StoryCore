#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include "Core/Choice.hpp"

namespace src {

struct Room {
    Room(std::string description, std::string name, 
         const std::vector<Choice>& choices = {}, size_t id = 0)
        : description(std::move(description)), name(std::move(name))
        , choices(choices), id(id) {}

    std::string description;
    std::string name;
    std::vector<src::Choice> choices;
    size_t id;
};

}
