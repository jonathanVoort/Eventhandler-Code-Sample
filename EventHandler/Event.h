#pragma once
#include <vector>
#include "FunctionWrapper.h"

struct SubscribedEvent
{
	int id;
	FunctionWrapper* target;

};

class Event
{
public:
	void Subscribe(int subscriber_id, FunctionWrapper* _target);
	void Unsubscribe(int subscriber_id);
	void NotifySubscribers();

private:

	// List of all functions subscribed to this event.
	std::vector<SubscribedEvent> subscribers;

	int GetIndex(int _id) const;

};

