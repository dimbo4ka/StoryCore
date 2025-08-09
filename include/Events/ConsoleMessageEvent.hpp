#pragma once

#include <iostream>
#include <string>

#include "Interfaces/IEvent.hpp"

namespace src {

class ConsoleMessageEvent : public IEvent {
public:
    ConsoleMessageEvent(const std::string& message)
        : message_(message) {}

    void Execute() override {
        std::cout << message_ << std::endl;
        std::cout << "Press Enter to continue..." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

private:
    std::string message_;
};

}