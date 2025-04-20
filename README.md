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

