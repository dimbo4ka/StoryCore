#pragma once

#include "GameState.hpp"

namespace src {

class IRenderer {
public:
    virtual ~IRenderer() = default;
    virtual void RenderText(src::GameState& game_state) = 0;
    virtual void RenderChoices(src::GameState& game_state) = 0;
    virtual size_t GetChoice(size_t choice_count) const = 0;
};

}
