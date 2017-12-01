#pragma once
#include "FunctionWrapper.h"
#include "Event.h"

template<typename T>
class Subscriber
{
public:
	typedef void(T::*MemberFunction)();

	Subscriber(int _id, MemberFunction _mem_func, T& _context, Event* _event)
	{
		this->id = _id;
		this->mem_func = _mem_func;
		this->context = &_context;
		this->event = _event;

		// The context and member function are linked to each other, so that it can be executed by the event.
		this->function = FunctionWrapper{ this->mem_func, this->context };
	}


	#pragma region RAII

	// Copy constructor
	Subscriber(const Subscriber& other) = delete;

	// Copy assignment operator
	Subscriber& operator=(const Subscriber& other) = delete;

	// Move constructor
	Subscriber(Subscriber&& other)
	{
		if (this != &other)
		{
			this->id = other.id;
			this->mem_func = other.mem_func;
			this->event = other.event;

			if (this->context == nullptr)
			{
				this->context = other.context;
			}

			if (this->context)
			{
				function = FunctionWrapper{ this->mem_func, this->context };
			}
		}
	}

	// Move assignment operator
	Subscriber& operator=(Subscriber&& other)
	{
		if (this != &other)
		{
			Unsubscribe();

			this->id = other.id;
			this->mem_func = other.mem_func;
			this->event = other.event;

			if (this->context)
			{
				function = FunctionWrapper{ this->mem_func, this->context };
			}

			try
			{
				Subscribe();
			}
			catch(std::invalid_argument& e) { }
		}

		return *this;
	}

	// Deconstructor
	~Subscriber()
	{
		Unsubscribe();
	}

	#pragma endregion

	void Subscribe()
	{
		if (event)
		{
			event->Subscribe(id, &function);
		}
		else
		{
			throw std::invalid_argument("Failed to subscribe, no available event was found.");
		}
	}

	void Unsubscribe()
	{
		if (event)
		{
			event->Unsubscribe(id);
		}
	}

private:

	// Identification to distinguish subscribers from each other.
	int id;

	// The event that the function wants to subscribe to.
	Event* event;

	// The context on which the function will be called.
	T* context;

	// Desired function to be subscribed to the event.
	MemberFunction mem_func;

	// Wrapper used to decouple subscriber from event.
	FunctionWrapper function;

};