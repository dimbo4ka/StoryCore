#pragma once

#include <algorithm>
#include <vector>

#include "Core/Room.hpp"
#include "Core/Item.hpp"

namespace src {

class GameState {
public:    
    size_t current_room_id() const {
        return current_room_id_;
    }

    void SetRoomId(size_t id) {
        current_room_id_ = id;
    }

    const src::Room& GetCurrentRoom() const {
        return rooms_[current_room_id_];
    }

    src::Room& GetCurrentRoom() {
        return rooms_[current_room_id_];
    }

    void AddRoom(const src::Room& room) {
        rooms_.push_back(room);
    }

    void AddItem(const src::Item& item) {
        inventory_.push_back(item);
    }

    const std::vector<src::Room>& rooms() const {
        return rooms_;
    }

    const std::vector<src::Item>& inventory() const {
        return inventory_;
    }

    bool HasItem(const std::string& name) const {
        return std::any_of(inventory_.begin(), inventory_.end(), [&](const src::Item& item) {
            return item.name() == name;
        });
    }

    bool RemoveItem(const std::string& name) {
        auto it = std::remove_if(inventory_.begin(), inventory_.end(), [&](const src::Item& item) {
            return item.name() == name;
        });
        if (it != inventory_.end()) {
            inventory_.erase(it, inventory_.end());
            return true;
        }
        return false;
    }

private:
    std::vector<src::Room> rooms_;
    std::vector<src::Item> inventory_;
    size_t current_room_id_ = 0;
};

}
