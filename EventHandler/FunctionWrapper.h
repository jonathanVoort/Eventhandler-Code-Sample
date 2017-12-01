#pragma once
#include <functional>

class FunctionWrapper
{
public:
	typedef std::function<void()> GenericFunction;

	FunctionWrapper()
	{

	}

	// Create the function.
	template<typename T>
	FunctionWrapper(void(T::*MemberFunction)(), T* context) : function{std::bind(MemberFunction, context)}
	{
	}

	// Call the function.
	void Trigger();

private:
	// Class that represents both the memberfunction and the context.
	GenericFunction function;
};

