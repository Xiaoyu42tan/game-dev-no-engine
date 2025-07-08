#pragma once

#include "Events/EventListener.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <mutex>
#include <unordered_set>
#include <unordered_map>

// threadsafe EventDispatcher class (singleton)
class EventDispatcher {
public:
    // notifies all subscribers, this should only ever called by the main thread
    void notify(const sf::Event& event);

    // no copying or assigning
    EventDispatcher(EventDispatcher &other) = delete;
    EventDispatcher& operator=(const EventDispatcher&) = delete;
    
    // only getting
    static EventDispatcher& getInstance();
private:
    std::mutex subscribersMutex;
    std::unordered_set<const EventListener*> subscribers;

    EventDispatcher() = default;

    friend class EventListener; // Give access to private subscribe/unsubscribe
    // thread safe
    void subscribe(const EventListener& listener);

    // thread safe
    void unsubscribe(const EventListener& listener);

};
