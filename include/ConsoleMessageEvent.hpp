#pragma once

#include <iostream>
#include <string>

#include "IEvent.hpp"

namespace src {

class ConsoleMessageEvent : public IEvent {
public:
    ConsoleMessageEvent(const std::string& message)
        : message_(message) {}

    void Execute() override {
        std::cout << message_ << std::endl;
    }

private:
    std::string message_;
};

}