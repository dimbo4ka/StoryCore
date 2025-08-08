#include "include/Entity.hpp"

namespace src {

Entity::Entity(const std::string& name, size_t id) 
    : name_(name), id_(id) {}

size_t Entity::id() const {
    return id_;
}

const std::string& Entity::name() const {
    return name_;
}

}