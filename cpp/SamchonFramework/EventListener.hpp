#pragma once

namespace samchon
{
    namespace library
    {
        class Event;

        enum class TYPE_EVENT_LISTENER : char
        {
            IN = 0x01,
            OUT = 0x02
        };

        typedef class IEventListener
        {
        private:
            TYPE_EVENT_LISTENER TypeOf;
        protected:
            IEventListener *pNext;
        public:
            IEventListener(TYPE_EVENT_LISTENER type) : pNext(nullptr)
            {
                this->TypeOf = type;
            }

            virtual void Dispatch(Event) = 0;

            friend class EventDispatcher;

        }*LPIEventListener;
    }
}