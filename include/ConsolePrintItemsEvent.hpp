#pragma once

#include <iostream>

#include "IEvent.hpp"
#include "GameState.hpp"

namespace src {

class ConsolePrintItemsEvent : public src::IEvent {
public:
    ConsolePrintItemsEvent(const src::GameState& game_state)
        : game_state_(game_state) {}

    void Execute() override {
        if (game_state_.inventory().empty()) {
            std::cout << "Inventory is empty." << std::endl;
            PrintPressEnter();
            return;
        }
        std::cout << "Items in inventory:" << std::endl;
        for (const auto& item : game_state_.inventory()) {
            std::cout << "- " << item.name() << ": " << item.description() << std::endl;
        }
        PrintPressEnter();
    }

private:
    const src::GameState& game_state_;

    void PrintPressEnter() const {
        std::cout << "Press Enter to continue..." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
};

}
