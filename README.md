# PARTICLE SIMULATOR
This is a cellular automata particle simulator. Similar to [The Powder Toy](https://powdertoy.co.uk/) and the Falling Everything engine used by [Noita](https://store.steampowered.com/app/881100/Noita/).

[Here](https://youtu.be/9GD_9Q7hKBQ) is a demonstration on Youtube.

<img width="774" height="739" alt="image" src="https://github.com/user-attachments/assets/e076fe42-4278-4a0d-a569-e66e3db524ae" />

<img width="935" height="746" alt="image" src="https://github.com/user-attachments/assets/d79b50a9-fd7c-4252-80be-e07218d14cf9" />

<img width="852" height="790" alt="image" src="https://github.com/user-attachments/assets/7884d541-4787-4f11-bf00-0c7321e7ce78" />

Currently the controls are:
- Next element: E
- Prev element: Q
- Zoom in/out: Scroll Wheel
- Place/delete: Left/Right click
- Pause: Space
- Change brush size: < and >

# HOW TO BUILD

### 1. Configuring for the first time
Make sure you are in the root of the repository. Run:
```cmd
cmake -B build
```

This generates the `/build` directory ready to be built.

If you get some error like `Running 'nmake' '-?' failed etc..` you probably have the incorrect **generator** specified. Specify a **generator** with `-G`:

```cmd
cmake -B build -G "Ninja"
```

I like to use Ninja cos its fast.

If you have other issues see the CMAKE HELP section below.

### 2. Building for the first time / Compiling after changes
Run from repository root:
```cmd
cmake --build build
```

This generates a `.bat` file in the root folder which will run the game.

NOTE: The `main` executable is in `/build` which was generated above. I wrapped `main` in the `.bat` file to make sure the DLLs are accessible in the PATH. Let me know if there is a cleaner way to do this.

### 2.1. Adding/removing a source file
Make sure you are adding the file in the `/src` directory. Then edit `CMakeLists.txt` in the root directory to include the new source file you added.

The relevant section in the `CMakeLists.txt` should look something like this

```cmake
############## ADD SOURCE FILES HERE ##############
add_executable(main 
    "src/main.cpp"
    ...
)
```

### 3. Running the game
Run:
```cmd
./run_main.bat
```

Again make sure you are in the root of the repository when you run this. Otherwise it will not work because of relative path issues with SFML.


# CMAKE HELP

### What is CMake?

Build systems essentially just generate and execute a bunch of bash commands that compile your code (so you dont have to type those commands yourself). "Ninja" and "Make" are example build systems.

**CMake automates your build systems so you dont have to type out Makefiles and Ninja builds yourself.** EVERYTHING related to building is specified in the CMakeLists.txt.

### 1. Install CMake here: https://cmake.org/download/

Make sure you can use the CLI by running:
```cmd
cmake --version
```
Make sure the version is >= 3.24 as specified by our CMakeLists.txt

### 2. Install a **generator** (Ninja)

Generators generate your build files. 

Install Ninja with whatever package manager you are using. On Windows I use Chocolatey:
```cmd
choco install ninja
```

You can install Chocolately here: https://chocolatey.org/install#individual

Now you can build with this **generator** specified 
```cmd
cmake -B build -G "Ninja"
```

