#pragma once

#include <iostream>
#include <string>

#include "GameState.hpp"
#include "ICondition.hpp"

namespace src {

class HasItemCondition : public src::ICondition {
public:
    explicit HasItemCondition(std::string item_name)
        : item_name_(item_name) {}

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