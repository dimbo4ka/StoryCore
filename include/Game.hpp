#pragma once

#include <memory>
#include <string>

#include "GameState.hpp"
#include "IRenderer.hpp"

namespace src {

class Game {
public:
    Game() = default;
    virtual ~Game() = default;
    
    void Run();
    void SetRenderer(std::unique_ptr<src::IRenderer> renderer);
    void LoadStory(const std::string& filename);
    src::GameState& GetGameState() {
        return game_state_;
    }

private:
    src::GameState game_state_;    
    std::unique_ptr<src::IRenderer> renderer_;
};

}
