cmake_minimum_required(VERSION 3.24)
project(ROGUELIKE)

set(CMAKE_CXX_STANDARD 17)

# turn DLL build on by default
option(BUILD_SHARED_LIBS "Build shared libraries" ON)

# find sfml
find_library(SFML_LIB
	sfml-graphics
	sfml-window 
	sfml-system
	sfml-audio
)

# download sfml if not found
if (NOT SFML_LIB)
    include(FetchContent)
    FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.x # 3.0.x is a branch name 
        GIT_SHALLOW ON # shallow clone, only downloads the latest commit instead of the full git history
        EXCLUDE_FROM_ALL # exclude things like SFML_BUILD_EXAMPLES, SFML_BUILD_DOC, SFML_BUILD_TEST_SUITE etc which we dont need
        SYSTEM) # suppress compiler warnings, assume external lib is well tested and correct
    FetchContent_MakeAvailable(SFML)
endif()

# add include directories here. the compiler will search these directories for the headers
include_directories(include)

############## ADD SOURCE FILES HERE ##############
add_executable(main 
    "src/main.cpp"
    "src/Engine.cpp"
    "src/World.cpp"
    "src/Particle.cpp"
    "src/ParticleGrid.cpp"
)

# Link to SFML
target_link_libraries(main PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
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
