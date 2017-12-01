#pragma once
#include <map>
#include "Event.h"
#include "Subscriber.h"

class EventManager
{
public:
	EventManager();

	template<typename T>
	Subscriber<T> SubscribeTo(int event_code, void(T::*function)(), T& context)
	{
		// Creat the event if it doesn't exist.
		if (events.find(event_code) == events.end())
		{
			events.emplace(event_code, Event{});
		}

		// Create a subscriber using the given member function and link it to the desired event.
		Subscriber<T> subscriber{ max_event_id++, function, context, &events[event_code] };

		return subscriber;
	}

	void HandleEvent(int event_code);

private:

	// Collection of all events that can be handled.
	std::map<int, Event> events;

	// The ID for the next subscription that is created.
	int max_event_id;

};

// List of events used for testing.
enum AvailableEvents
{
	EXAMPLE_EVENT = 1
};
