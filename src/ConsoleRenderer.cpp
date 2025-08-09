#include "include/ConsoleRenderer.hpp"

#include <iostream>

namespace src {

void ConsoleRenderer::RenderText(src::GameState& game_state) {
    std::cout << game_state.GetCurrentRoom().description << std::endl;
}

size_t ConsoleRenderer::RenderChoices(src::GameState& game_state) {
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