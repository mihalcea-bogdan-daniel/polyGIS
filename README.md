# polyGIS Add-On CMake Project and Template

This repository contains a CMake template for Archicad Add-On Development. You can use it to generate native Visual Studio or XCode project or to develop an Add-On directly in Visual Studio Code without using any other environments.
**Important** : This template is based on the  [GRAPHISOFT Official Template](https://github.com/GRAPHISOFT/archicad-addon-cmake.git)  

## Prerequisites

- [CMake](https://cmake.org) (3.16 minimum version is needed).
- [Python](https://www.python.org) for resource compilation (version 2.7+ or 3.8+).

## Build

- [Download the CMake Template from here](https://github.com/arhitextura/polyGIS/archive/refs/heads/master.zip).
- [Download the Archicad Add-On Development Kit from here](http://archicadapi.graphisoft.com).
- Generate the IDE project with CMake, and set the following variables:
  - `AC_API_DEVKIT_DIR`: The root folder of the installed Archicad Add-On Development Kit. You can also set an environment variable with the same name so you don't have to provide this value during project generation.
  - `AC_ADDON_NAME`: (optional) The name of the project file and the result binary Add-On file (default is "ExampleAddOn").
  - `AC_ADDON_LANGUAGE`: (optional) The language code of the Add-On (default is "INT").
- Generate the cmake project using the CMake Build.bat
- To release your Add-On you have to modify the MDID in the "Sources/AddOn/Private.hpp" file.  
  - Local ID is your AddOns ID and Developer ID is yhe developers account ID you can get these after you have a developer account;

### Visual Studio (Windows)  

For Windows this it is not necessary, you can run the  CMake Build.bat and it will do it for you
Run these commands from the command line.

``` bash
mkdir Build
cd Build
cmake -G "Visual Studio 15 2017" -A "x64" -DAC_API_DEVKIT_DIR="C:\Program Files\GRAPHISOFT\API Development Kit 24.3009" AC_ADDON_NAME="polyGIS" ..
cd ..
```

### XCode (MacOS)

Run these commands from the command line.

``` bash
mkdir Build
cd Build
cmake -G "Xcode" -DAC_API_DEVKIT_DIR=/Applications/GRAPHISOFT\ ARCHICAD\ API\ DevKit\ 24.3009 ..
cd ..
```

### Visual Studio Code (Platform Independent)

- Install the "CMake Tools" extension for Visual Studio Code.
- Set the "AC_API_DEVKIT_DIR" environment variable to the installed Development Kit folder.
- Open the root folder in Visual Studio Code, configure and build the solution.

## Archicad Compatibility

This template is tested with all Archicad versions starting from Archicad 23.

## Use in Archicad

To use the Add-On in Archicad, you have to add your compiled .apx file in Add-On Manager. The example Add-On registers a new command into the Options menu. Please note that the example Add-On works only in the demo version of Archicad. In order to work in normal mode you have to modify Private.hpp.  

``` c++
/*
This file is added to the .gitignore file
DO NOT REMOVE IT FROM .gitignore, CONTAINS PERSONAL INFORMATION
Here you can store API Tokens, third party login informations etc.
*/
#ifndef PRIVATE_HPP
#define PRIVATE_HPP

#define DEVELOPER_ID 1 /*Replace with developer ID*/
#define LOCAL_ID 1 /*Replace with local ID*/
#endif
```

You can start Archicad in demo mode with the following command line commands:  

- Windows: `ARCHICAD.exe -DEMO` - Archicad.exe containing folder must be added to the PATH Variables
- MacOS: `ARCHICAD\ 24.app/Contents/MacOS/ARCHICAD -demo`

## Modifications

If you use the same source structure as the template, you probably won't have to modify anything in the project generation process.

CMakeLists.txt includes every Archciad modules available in the Development Kit.

## Possible Improvements

- Multilanguage support (provide example for another localized version).
- The generated XCode source structure could be improved.
