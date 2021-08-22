# MSU_STARX_EMG_Feature_Toolkit

## How to use
For a example to using this library look into the ***/examples*** folder found on this repository. This example would run all functions found in the library with a C++ compiler. A makefile has been provided within ***/source*** to compile this library. 

To use this library for Arduino, within ***/source/emgToolbox.h*** uncomment the line ***//#include "Arduino.h"***. You can setup in the Arduino IDE like you would in main.cpp example.

## Documentation
Please refer to intrinsic documentation to the different function descriptions and information on how the class works.

## Google Test
In terminal cd into the /unitTest folder and run the commands below.
```
  cmake -S . -B build
  
  cmake --build build
  
  cd build && ctest
```
This will reveal the tests and show if they pass/fail.
