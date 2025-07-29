#pragma once

#include <string>
#include <functional>
#include <stdint.h>

namespace Earl
{
    // we want this to be buffered in future
    enum class EventType
    {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        KeyPressed,
        KeyReleased,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    // We use bitwise operations to categorize events because it allows us to combine multiple categories
    enum class EventCategory : uint8_t
    {
        None = 0,
        EventCategoryApplication = 1 << 0,
        EventCategoryInput = 1 << 1,
        EventCategoryKeyboard = 1 << 2,
        EventCategoryMouse = 1 << 3,
        EventCategoryMouseButton = 1 << 4
    };

    template <typename DerivedEvent>
    class EventBase
    {
    public:
        virtual int GetCategoryFlags() const = 0;
        static EventType GetStaticType() { return DerivedEvent::StaticType; }

        // runtime accessible verion of the type
        EventType GetEventType() const { return DerivedEvent::StaticType; }
        const char *GetName() const { return DerivedEvent::StaticName; }

        bool IsInCategory(EventCategory category) const
        {
            return GetCategoryFlags() & static_cast<int>(category);
        }
    };
}
