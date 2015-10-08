#pragma once
#include <samchon/API.hpp>

namespace samchon
{
	namespace library
	{
		class EventDispatcher;

		/**
		 * @ingroup event
		 *
		 * @brief Represent an event running on background.
		 *
		 * @details
		 * <p> The Event class is used as the base class for the creation of Event objects, 
		 * which are passed as parameters to event listeners when an event occurs. </p>
		 *
		 * <p> The properties of the Event class carry basic information about an event, 
		 * such as the event's type or source (who made the event) of the event. </p>
		 *
		 * <p> For many events, such as the events represented by the Event class constants, 
		 * this basic information is sufficient. Other events, however, may require more detailed 
		 * information. </p>
		 * 
		 * @note 
		 * <p> Event is a candidate to be depreciated. </p>
		 * <p> Since C++11, calling member method of a class by a new thread passing by static 
		 * method and using void pointer are recommeded to avoid. As the reason, using <i>std::thread</i> 
		 * and <i>std::bind will</i> be better. </p>
		 *
		 *	\li std::thread: http://www.cplusplus.com/reference/thread/thread/
		 *	\li std::bind: http://www.cplusplus.com/reference/functional/bind/
		 *
		 * @see samchon::library
		 * @author Jeongho Nam
		 */
		class SAMCHON_FRAMEWORK_API Event
		{
		public:
			enum TYPES : char
			{
				ACTIVATE = 0x01,
				COMPLETE = 0x02,
				REMOVED = 0xFF
			};

		protected:
			/**
			 * @brief Source of the event
			 */
			EventDispatcher *source;

			/**
			 * @brief Type of the event
			 */
			int type;

		public:
			/**
			 * @brief Construct from source and type
			 * @details The event object owns its source and type
			 *
			 * @param source Source of the event; who made the event
			 * @param type Type of the event
			 */
			Event(EventDispatcher*, int);
			virtual ~Event() = default;
			
			/**
			 * @brief Get source of the Event
			 */
			auto getSource() const -> EventDispatcher*;

			/**
			 * @brief Get type of the Event
			 */
			auto getType() const -> int;
		};
	};
};