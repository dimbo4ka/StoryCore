#pragma once

namespace src {
    
class IEvent {
public:
    virtual void Execute() {}
    virtual ~IEvent() = default;
};

}
