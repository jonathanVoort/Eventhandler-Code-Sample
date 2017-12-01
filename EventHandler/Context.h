#pragma once
#include "Subscriber.h"
#include "EventManager.h"
#include <iostream>

class Context
{
public:
	Context(int _id, EventManager& event_manager);
	void TargetFunction();
	int GetCallCount() const;
	
private:
	// Identification used to distinguish the function calls in the example.
	const int id;

	// The amount of times that the target function has been called.
	int call_count;

	// Store the subscribe in the context so that it automatically unsubscribes on deconstruction.
	Subscriber<Context> subscriber;
};

