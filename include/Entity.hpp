#pragma once

#include <cstddef>
#include <string>

namespace src {

class Entity {
public:
    Entity(const std::string& name, size_t id)
        : name_(name), id_(id) {}
    virtual ~Entity() = default;

    size_t id() const {
        return id_;
    }
    const std::string& name() const {
        return name_;
    }

protected:
    std::string name_;
    size_t id_;
};

}