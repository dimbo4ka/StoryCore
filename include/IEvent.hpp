#pragma once

namespace src {
    
class IEvent {
public:
    virtual void Execute() = 0;
    virtual ~IEvent() = default;
};

}
