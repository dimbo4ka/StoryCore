#pragma once

#include <memory>
#include <string>

#include "Core/GameState.hpp"
#include "Interfaces/IRenderer.hpp"

namespace src {

class Game {
public:
    void Run();
    void SetRenderer(std::unique_ptr<src::IRenderer> renderer);
    void LoadStory(const std::string& filename);
    src::GameState& GetGameState();
    void SetEndMessage(std::string message);

private:
    src::GameState game_state_;    
    std::unique_ptr<src::IRenderer> renderer_;
    std::string end_message_ = "Game over.";
};

}
