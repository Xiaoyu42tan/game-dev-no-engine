#include "Events/EventDispatcher.h"


#include <iostream>

void EventDispatcher::subscribe(const EventListener& listener) {
    std::lock_guard<std::mutex> lock(subscribersMutex);
    subscribers.insert(&listener);
}

void EventDispatcher::unsubscribe(const EventListener& listener) {
    std::lock_guard<std::mutex> lock(subscribersMutex);
    subscribers.erase(&listener);
}



void EventDispatcher::notify(const sf::Event& event) {
    std::lock_guard<std::mutex> lock(subscribersMutex);

    for (auto subscriber : subscribers) {
        subscriber->onEvent(event);
    }
}


EventDispatcher& EventDispatcher::getInstance() {
    // magic statics! (also thread safe since c++11)
    static EventDispatcher instance;
    return instance;
}

