#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include "Choice.hpp"
#include "Entity.hpp"

namespace src {

struct Room {
    Room(const std::string& description, const std::string& name, 
         const std::vector<Choice>& choices = {}, size_t id = 0)
        : description(description), name(name), choices(choices), id(id) {}

    std::string description;
    std::string name;
    std::vector<src::Choice> choices;
    std::vector<src::Entity> entities;
    size_t id;
};

}
