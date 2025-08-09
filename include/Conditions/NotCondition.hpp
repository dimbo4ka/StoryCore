#pragma once

#include "Interfaces/ICondition.hpp"

namespace src {

class NotCondition : public ICondition {
public:
    NotCondition(std::shared_ptr<ICondition> condition)
        : condition_(std::move(condition)) {}

    bool IsMet(const GameState& game_state) const override {
        return !condition_->IsMet(game_state);
    }

private:
    std::shared_ptr<ICondition> condition_;
};

}