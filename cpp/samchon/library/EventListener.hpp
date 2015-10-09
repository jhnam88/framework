#pragma once

typedef char TYPE_LISTENER;
typedef char UUID_LISTENER;

namespace samchon
{
    namespace library
    {
        class Event;

        typedef class IEventListener
        {
        private:
            TYPE_LISTENER TypeOf;
            UUID_LISTENER UuidOf;
        protected:
            IEventListener *pNext;
        public:
            IEventListener(TYPE_LISTENER type, UUID_LISTENER uuid) : pNext(nullptr)
            {
                this->TypeOf = type;
                this->UuidOf = uuid;
            }

            virtual void Dispatch(Event) = 0;

            UUID_LISTENER GetUUID()
            {
                return this->UuidOf;
            }

            TYPE_LISTENER GetType()
            {
                return this->TypeOf;
            }

            friend class EventDispatcher;

        }*LPIEventListener;

        template<class __listener>
        __listener *CreateEventListender(TYPE_LISTENER type, UUID_LISTENER uuid)
        {
            IEventListener *pTmpClass;

            if (type == 0 && uuid == 0) return nullptr;
            pTmpClass = new __listener(type, uuid);

            return pTmpClass;
        }
    }
}
