#include "include/Core/Game.hpp"

#include <iostream>

namespace src {

void Game::SetRenderer(std::unique_ptr<src::IRenderer> renderer) {
    renderer_ = std::move(renderer);
}

void Game::Run() {
    if (!renderer_) {
        throw std::runtime_error("Renderer not set.");
    }
    while (true) {
        const auto& choices = game_state_.GetCurrentRoom().choices;
        if (choices.empty()) {
            std::cout << end_message_ << std::endl;
            break;
        }  
        renderer_->RenderText(game_state_);
        size_t choice_count = renderer_->RenderChoices(game_state_);
        
        size_t choice_index = renderer_->GetChoice(choice_count);
        const auto& choice = choices[choice_index - 1];
        for (const auto& event : choice.events()) {
            event->Execute();
        }

        game_state_.SetRoomId(choice.next_room_id());
    }
}

src::GameState& Game::GetGameState() {
    return game_state_;
}

void Game::SetEndMessage(std::string message) {
    end_message_ = std::move(message);
}

}