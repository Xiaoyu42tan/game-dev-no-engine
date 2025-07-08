#pragma once

#include <functional> // for std::hash
#include <SFML/System/Vector2.hpp>

struct PairHash {
    inline size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};


struct Vector2iHash {
    inline size_t operator()(const sf::Vector2i& vec) const {
        return std::hash<int>()(vec.x) ^ (std::hash<int>()(vec.y) << 1);
    }
};

