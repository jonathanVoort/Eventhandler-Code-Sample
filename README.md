Developed by Jonathan van der Voort

# Eventhandler
This code sample was created to use within a college project with the objective of building a game engine in SDL. However, the sample could also be used in other contexts that desire event-driven designs.

The sample contains multiple classes where *EventManager* and *Subscriber* are used as interface to the consumer. Using these classes the consumer can subscribe functions gathered from different contexts to one event.

##### EventManager
The EventManager has the responsibility for managing and storing different events. In the current code sample the events are distinguished by an Integer named key_code which represents a random button press.

EventManager also acts as an interface to the user for subscribing to events or triggering a specific Event.

##### Event
An Event represents a specific action where other classes want to listen to, in this case this is a button press on the keyboard represented as an Integer named key_code. An Event contains multiple subscribed functions (FunctionWrapper) which will be fired when the event is triggered.

##### Subscriber<typename>
Subscriber is the RAII wrapper that allows the subscribed function to decouple from the Event. The subscriber is included in the context to act as an access point for the context to subscribe or unsubscribe to an event. It also makes sure that the event is always unsubscribed when the context goes out of scope.

##### FunctionWrapper
The FunctionWrapper represents a member function binded to a context, this is realised by using the std class std::function. FunctionWrapper is used by Subscriber to allow decoupling between a context and an event.

##### Context
The context is basically an example of any object that contains a function that needs to be subscribed to an Event.
