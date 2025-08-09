#pragma once

#include "Core/GameState.hpp"

namespace src {
class GameState;

class ICondition {
public:
    virtual bool IsMet(const src::GameState&) const = 0;
    virtual ~ICondition() = default;
};

}