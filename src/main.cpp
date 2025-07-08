#include "Engine.h"

int main() {
    Engine engine({1920 / 2, 1080 / 2}, "Some name for the window");

    engine.run();
}

