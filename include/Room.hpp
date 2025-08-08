#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include "Choice.hpp"

namespace src {

struct Room {
    std::string description;
    std::string name;
    std::vector<src::Choice> choices;
    size_t id;
};

}
