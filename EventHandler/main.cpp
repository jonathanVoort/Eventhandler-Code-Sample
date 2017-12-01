#include "EventManager.h"
#include "Context.h"
#include <iostream>

int main()
{
	// Simple Use Case
	EventManager event_manager;

	Context A{ 1, event_manager };
	Context B{ 2, event_manager };
	event_manager.HandleEvent(EXAMPLE_EVENT);

	std::cin.get();

	return 0;
}