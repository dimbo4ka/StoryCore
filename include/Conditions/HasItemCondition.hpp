#pragma once

#include <iostream>
#include <string>

#include "Core/GameState.hpp"
#include "Interfaces/ICondition.hpp"

namespace src {

class HasItemCondition : public src::ICondition {
public:
    HasItemCondition(std::string item_name)
        : item_name_(std::move(item_name)) {}

    bool IsMet(const src::GameState& game_state) const override {
        for (const auto& item : game_state.inventory()) {
            if (item.name() == item_name_) {
                return true;
            }
        }
        return false;
    }
private:
    std::string item_name_;
};

}