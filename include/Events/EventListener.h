#pragma once

#include <SFML/Window/Event.hpp>

#include <functional>

// forward decl to prevent circular dependency
class EventDispatcher;

// EventListener listens to ALL sf::Event
class EventListener {
public:
    // pass in a function with signature fn(const sf::Event&) -> void
    EventListener(std::function<void(const sf::Event&)> onEventFunction);

    ~EventListener();
private:
    EventDispatcher& dispatcher;

    std::function<void(const sf::Event&)> onEventFunction;

    friend class EventDispatcher; // only dispatcher should call onEvent
    void onEvent(const sf::Event& event) const;
};

