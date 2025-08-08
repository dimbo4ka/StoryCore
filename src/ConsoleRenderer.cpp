#include "include/ConsoleRenderer.hpp"

#include <iostream>

namespace src {

void ConsoleRenderer::RenderText(src::GameState& game_state) {
    std::cout << game_state.GetCurrentRoom().description << std::endl;
}

void ConsoleRenderer::RenderChoices(src::GameState& game_state) {
    const auto& choices = game_state.GetCurrentRoom().choices;
    for (size_t i = 0; i < choices.size(); ++i) {
        std::cout << i + 1 << ". " << choices[i].description() << std::endl;
    }
}

size_t ConsoleRenderer::GetChoice(size_t choice_count) const {
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

}