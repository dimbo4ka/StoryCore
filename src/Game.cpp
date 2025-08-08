#include "include/Game.hpp"

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
            std::cout << "Game over" << std::endl;
            break;
        }  
        renderer_->RenderText(game_state_);
        renderer_->RenderChoices(game_state_);
        
        size_t choice_index = renderer_->GetChoice(choices.size());
        const auto& choice = choices[choice_index - 1];
        for (const auto& event : choice.events()) {
            event->Execute();
        }

        game_state_.SetRoomId(choice.next_room_id());
    }
}

}