#pragma once

#include "Behaviours/Behaviour.h"

#include <unordered_map>
#include <memory>
#include <typeindex>

// forward decl
class Particle;

class BehaviourSet {
public:
    BehaviourSet(Particle& particle);

    template <typename T>
    void add(std::shared_ptr<T> behaviour);

    template <typename T>
    bool has() const;

    template <typename T>
    std::shared_ptr<T> get() const;
private:
    Particle& particle;

    std::unordered_map<std::type_index, std::shared_ptr<Behaviour>> behaviours;
};

// template method definitions must be defined in the header file

template <typename T>
void BehaviourSet::add(std::shared_ptr<T> behaviour) {
    behaviours[typeid(T)] = behaviour;
}

template <typename T>
bool BehaviourSet::has() const {
    return behaviours.find(typeid(T)) != behaviours.end();
}

template <typename T>
std::shared_ptr<T> BehaviourSet::get() const {
    auto it = behaviours.find(typeid(T));
    assert(it != behaviours.end());
    return std::dynamic_pointer_cast<T>(it->second);
}


