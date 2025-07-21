#include <cmath>
#include <random>

inline bool coinFlip() {
    static thread_local std::mt19937 rng(std::random_device{}());
    static thread_local std::uniform_int_distribution<int> dist(0, 1);
    return dist(rng) == 0;
}

inline bool randomChance(float probability) {
    static thread_local std::mt19937 rng(std::random_device{}());
    static thread_local std::uniform_real_distribution<float> dist(0.0f, 1.0f);
    return dist(rng) < probability;
}

/*
turns float into integer stochastically. works for positive and negative numbers

EXAMPLE: stochasticRound(3.14) = 3 + "14% chance of 1"
*/
inline int stochasticRound(float value) {
    bool isNegative = value < 0;

    value = std::abs(value);

    unsigned int base = static_cast<unsigned int>(std::floor(value));
    float fraction = value - base;

    int result = base + randomChance(fraction);

    if (isNegative) return -result;
    return result;
}
