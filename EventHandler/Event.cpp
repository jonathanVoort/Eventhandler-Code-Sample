#include "Event.h"

void Event::Subscribe(int subscriber_id, FunctionWrapper* _target)
{
	if (GetIndex(subscriber_id) == -1)
	{
		SubscribedEvent subscribed_event;
		subscribed_event.id = subscriber_id;
		subscribed_event.target = _target;
		subscribers.push_back(subscribed_event);
	}
}

void Event::Unsubscribe(int subscriber_id)
{
	int index = GetIndex(subscriber_id);

	if (index != -1)
	{
		subscribers.erase(subscribers.begin() + index);
	}
}

void Event::NotifySubscribers()
{
	for (SubscribedEvent subscribed_event : subscribers)
	{
		if (subscribed_event.target)
		{
			subscribed_event.target->Trigger();
		}
	}
}

/* Retrieve the vector index of the given subscriber_id
 Success: Returns the index of the subscriber.
 Fail: Returns -1.
*/
int Event::GetIndex(int subscriber_id) const
{
	for (int i = 0; i < subscribers.size(); i++)
	{
		if (subscribers[i].id == subscriber_id)
		{
			return i;
		}
	}

	return -1;
}
