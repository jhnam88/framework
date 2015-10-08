#pragma once

typedef char TYPE_EVENT_LISTENER;

namespace samchon
{
    namespace library
    {
        class Event;

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