#pragma once

#include <string>

namespace src {

class Item {
public:
    Item(std::string name, std::string description = "")
        : name_(std::move(name)), description_(std::move(description)) {}

    const std::string& name() const { 
        return name_; 
    }
    const std::string& description() const { 
        return description_; 
    }

private:
    std::string name_;
    std::string description_;
};

}