#include <Earl/Events/event.hpp>
#include <type_traits>

namespace Earl
{
    inline EventCategory operator|(EventCategory lhs, EventCategory rhs)
    {
        using T = std::underlying_type_t<EventCategory>;
        return static_cast<EventCategory>(static_cast<T>(lhs) | static_cast<T>(rhs));
    }

    inline EventCategory operator&(EventCategory lhs, EventCategory rhs)
    {
        using T = std::underlying_type_t<EventCategory>;
        return static_cast<EventCategory>(static_cast<T>(lhs) & static_cast<T>(rhs));
    }

    inline EventCategory &operator|=(EventCategory &lhs, EventCategory rhs)
    {
        lhs = lhs | rhs;
        return lhs;
    }
}
