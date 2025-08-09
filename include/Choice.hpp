#pragma once

#include <memory>
#include <string>
#include <vector>

#include "ICondition.hpp"
#include "IEvent.hpp"
#include "Room.hpp"

namespace src {

class Choice {
public:
    Choice(std::string description, size_t id = 0)
        : description_(std::move(description)), next_room_id_(id) {}

    const std::string& description() const {
        return description_;
    }

    bool IsAvailable(const src::GameState& game_state) const {
        for (const auto& condition : conditions_) {
            if (!condition->IsMet(game_state)) {
                return false;
            }
        }
        return true;
    }

    void AddEvent(std::shared_ptr<src::IEvent> event) {
        events_.push_back(event);
    }

    void AddCondition(std::shared_ptr<src::ICondition> condition) {
        conditions_.push_back(condition);
    }

    const std::vector<std::shared_ptr<src::IEvent>>& events() const {
        return events_;
    }
    
    std::vector<std::shared_ptr<src::IEvent>>& events() {
        return events_;
    }
    
    const std::vector<std::shared_ptr<src::ICondition>>& conditions() const {
        return conditions_;
    }

    std::vector<std::shared_ptr<src::ICondition>>& conditions() {
        return conditions_;
    }

    size_t next_room_id() const {
        return next_room_id_;
    }

private:
    std::string description_;
    std::vector<std::shared_ptr<src::ICondition>> conditions_;
    std::vector<std::shared_ptr<src::IEvent>> events_;
    size_t next_room_id_;
};

}