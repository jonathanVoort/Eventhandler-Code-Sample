#include "EventManager.h"



EventManager::EventManager()
{
	max_event_id = 1;
}

void EventManager::HandleEvent(int event_code)
{
	if (events.find(event_code) != events.end())
	{
		events[event_code].NotifySubscribers();
	}
}
