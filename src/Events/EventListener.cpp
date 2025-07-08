#include "Events/EventListener.h"

#include "Events/EventDispatcher.h"


EventListener::EventListener(std::function<void(const sf::Event&)> onEventFunction) 
    : dispatcher(EventDispatcher::getInstance())
    , onEventFunction(onEventFunction)
{
    dispatcher.subscribe(*this);
}

EventListener::~EventListener() {
    dispatcher.unsubscribe(*this);
}

void EventListener::onEvent(const sf::Event& event) const {
    onEventFunction(event);
}

