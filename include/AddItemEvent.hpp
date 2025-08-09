#pragma once

#include "IEvent.hpp"
#include "GameState.hpp"

namespace src {

class AddItemEvent : public IEvent {
public:
    AddItemEvent(const std::string& item_name, GameState& game_state)
        : item_name_(item_name), game_state_(game_state) {}

    void Execute() override {
        game_state_.AddItem(Item(item_name_));
    }

private:
    std::string item_name_;
    GameState& game_state_;
};

}
