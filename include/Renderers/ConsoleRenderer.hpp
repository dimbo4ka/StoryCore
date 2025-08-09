#pragma once

#include <iostream>

#include "Interfaces/IRenderer.hpp"

namespace src {

class ConsoleRenderer : public IRenderer {
public:
    ~ConsoleRenderer() = default;
    void RenderText(src::GameState& game_state) override {
        std::cout << game_state.GetCurrentRoom().description << std::endl;
    }
    size_t RenderChoices(src::GameState& game_state) override {
        auto& choices = game_state.GetCurrentRoom().choices;
        size_t choice_count = 1;
        size_t write_index = 0;
        for (size_t i = 0; i < choices.size(); ++i) {
            if (!choices[i].IsAvailable(game_state))
                continue;
            if (write_index != i)
                std::swap(choices[write_index], choices[i]);

            std::cout << choice_count << ". " << choices[write_index].description() << std::endl;
            ++write_index;
            ++choice_count;
        }
        return choice_count;
    }

    size_t GetChoice(size_t choice_count) const override {
        size_t choice;
        while (true) {
            std::cout << "> ";
            std::cin >> choice;
            if (choice >= 1 && choice <= choice_count) {
                return choice;
            }
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
};

}