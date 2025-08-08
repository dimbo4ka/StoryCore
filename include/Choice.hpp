#pragma once

#include <memory>
#include <string>
#include <vector>

#include "IEvent.hpp"
#include "Room.hpp"

namespace src {

class Choice {
public:
    Choice(const std::string& description, size_t id = 0)
        : description_(description), next_room_id_(id) {}

    const std::string& description() const {
        return description_;
    }

    bool IsAvailable() const {
        return true;
    }

    void AddEvent(std::shared_ptr<src::IEvent> event) {
        events_.push_back(event);
    }

    const std::vector<std::shared_ptr<src::IEvent>>& events() const {
        return events_;
    }

    size_t next_room_id() const {
        return next_room_id_;
    }

private:
    std::string description_;
    std::vector<std::shared_ptr<src::IEvent>> events_{};
    size_t next_room_id_;
};

}