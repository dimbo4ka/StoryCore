#pragma once

#include <cstddef>
#include <string>

namespace src {

class Entity {
public:
    Entity(const std::string& name, size_t id);
    virtual ~Entity() = default;

    size_t id() const;
    const std::string& name() const;

protected:
    std::string name_;    
    size_t id_;
};

}