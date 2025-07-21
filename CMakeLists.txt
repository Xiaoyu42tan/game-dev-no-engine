cmake_minimum_required(VERSION 3.24)
project(ROGUELIKE)

set(CMAKE_CXX_STANDARD 17)

# turn DLL build on by default
option(BUILD_SHARED_LIBS "Build shared libraries" ON)

# find sfml
set(SFML_LOCAL_LIB_DIR "${CMAKE_BINARY_DIR}/_deps/sfml-build/lib")

find_library(SFML_GRAPHICS_LIB sfml-graphics PATHS ${SFML_LOCAL_LIB_DIR} NO_DEFAULT_PATH)
find_library(SFML_WINDOW_LIB   sfml-window   PATHS ${SFML_LOCAL_LIB_DIR} NO_DEFAULT_PATH)
find_library(SFML_SYSTEM_LIB   sfml-system   PATHS ${SFML_LOCAL_LIB_DIR} NO_DEFAULT_PATH)
find_library(SFML_AUDIO_LIB    sfml-audio    PATHS ${SFML_LOCAL_LIB_DIR} NO_DEFAULT_PATH)

if (NOT SFML_GRAPHICS_LIB OR NOT SFML_WINDOW_LIB OR NOT SFML_SYSTEM_LIB OR NOT SFML_AUDIO_LIB)
    message(STATUS "SFML NOT Found! Fetching from GitHub...")
    include(FetchContent)
    FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
    )
    FetchContent_MakeAvailable(SFML)
else()
    message(STATUS "SFML Found!")
endif()


# add include directories here. the compiler will search these directories for the headers
include_directories("include")
include_directories("${CMAKE_BINARY_DIR}/_deps/sfml-src/include")

############## ADD SOURCE FILES HERE ##############
add_executable(main 
    # System
    "src/main.cpp"
    "src/Engine.cpp"
    "src/World.cpp"
    "src/Events/EventDispatcher.cpp"
    "src/Events/EventListener.cpp"
    "src/Brush.cpp"

    # Add new Particles here
    "src/Particles/ParticleGrid.cpp"
    "src/Particles/ParticleFactory.cpp"
    "src/Particles/Particle.cpp"
    "src/Particles/DebugSolid.cpp"
    "src/Particles/Empty.cpp"
    "src/Particles/Sand.cpp"
    "src/Particles/SandSource.cpp"
    "src/Particles/Water.cpp"
    "src/Particles/Smoke.cpp"
    "src/Particles/Fire.cpp"
    "src/Particles/Wood.cpp"
    "src/Particles/Ash.cpp"

    # Add new Particle Behaviours here
    "src/Behaviours/Behaviour.cpp"
    "src/Behaviours/BehaviourSet.cpp"
    "src/Behaviours/PowderLike.cpp"
    "src/Behaviours/LiquidLike.cpp"
    "src/Behaviours/Spawner.cpp"
    "src/Behaviours/Temporary.cpp"
    "src/Behaviours/Flammable.cpp"
)

# Link to SFML
target_link_libraries(main PRIVATE
    ${SFML_GRAPHICS_LIB}
    ${SFML_WINDOW_LIB}
    ${SFML_SYSTEM_LIB}
    ${SFML_AUDIO_LIB}
)

############## Post build launcher script ##############

# Set the path to the executable and SFML DLL directory
set(SFML_DLL_DIR "${CMAKE_BINARY_DIR}/_deps/sfml-build/bin")
set(EXE_PATH "${CMAKE_BINARY_DIR}/main.exe")

# Windows .bat launcher script
set(BAT_PATH "run_main.bat")
file(WRITE "${BAT_PATH}" 
  "@echo off\n"
  "set PATH=${SFML_DLL_DIR};%PATH%\n"
  "echo Running ${EXE_PATH}\n"
  "\"${EXE_PATH}\"\n"
)
