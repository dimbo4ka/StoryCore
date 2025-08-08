#pragma once

#include <vector>

#include "Room.hpp"

namespace src {

class GameState {
public:
    GameState() = default;
    ~GameState() = default;
    
    size_t current_room_id() const {
        return current_room_id_;
    }

    void SetRoomId(size_t id) {
        current_room_id_ = id;
    }

    src::Room GetCurrentRoom() const {
        return rooms_[current_room_id_];
    }

    void AddRoom(const src::Room& room) {
        rooms_.push_back(room);
    }

private:
    std::vector<src::Room> rooms_;
    size_t current_room_id_ = 0;
};

}
