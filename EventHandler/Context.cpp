#include "Context.h"

// The subscriber is created using the event_manager.
Context::Context(int _id, EventManager & event_manager) : 
	subscriber{event_manager.SubscribeTo(EXAMPLE_EVENT, &Context::TargetFunction, *this)},
	id{_id}
{
	call_count = 0;

	try
	{
		subscriber.Subscribe();
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Context::TargetFunction()
{
	std::cout << "Context " << this->id << " called!" << std::endl;

	call_count++;
}

int Context::GetCallCount() const
{
	return this->call_count;
}
