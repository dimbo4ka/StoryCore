#pragma once

#include "IRenderer.hpp"

namespace src {

class ConsoleRenderer : public IRenderer {
public:
    ~ConsoleRenderer() = default;
    void RenderText(src::GameState& game_state) override;
    void RenderChoices(src::GameState& game_state) override;
    size_t GetChoice(size_t choice_count) const override;
};

}