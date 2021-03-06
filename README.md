# EquinoxC logging engine
**Thread safety C99/C11 logger with MACRO interface**

***To version written in C++, please visit: https://github.com/jwolak/Equinox-Logger***

**Logger with support logging to file, console or both. Four levels avaliable:**
- Error 
- Warning
- Debug
- Disabled

## Features

- settable log level
- settable output direction (console, file or both)
- interface as enjoyable C-style macros
- powered by C99/C11 (no mistake..I've not meant C++11)
- unit tests powered by Unity (no...not 3D) taken from: https://github.com/ThrowTheSwitch/Unity


## Building for source

###### For EquinoxCLoggerDemo:

```sh
cd build/
cmake CMakeLists.txt
make
```

###### For UnitTests:

```sh
To build Unity test framework (visit: https://github.com/ThrowTheSwitch/Unity)
cd UnityTestFramework/Unity/
cmake CMakeLists.txt
make

cd UnitTests/build
cmake CMakeLists.txt
make
```
## Example:

Include "LoggerC.h" from "EquinoxC-Logger/src/" to your source code:
```sh
See: src/main.cpp
```
```sh
#include <stdio.h>
#include "LoggerC.h"

int main() {

  SET_LOG_LEVEL(DEBUG);
  SET_LOG_LOGGER_OUTPUT(CONSOLE_AND_FILE);
  printf("\nDEBUG level set and all messages printed:\n");
  LOG_ERROR("%s", "Tests ERROR");
  LOG_WARNING("%s", "Tests WARNING");
  LOG_DEBUG("%s", "Tests DEBUG");

  SET_LOG_LEVEL(WARNING);
  SET_LOG_LOGGER_OUTPUT(CONSOLE_AND_FILE);
  printf("\nWARNING level set and ERROR and WARNING messages printed:\n");
  LOG_ERROR("%s", "Tests ERROR");
  LOG_WARNING("%s", "Tests WARNING");
  LOG_DEBUG("%s", "Tests DEBUG");

  SET_LOG_LEVEL(ERROR);
  SET_LOG_LOGGER_OUTPUT(CONSOLE_AND_FILE);
  printf("\nERROR level set and only ERROR message printed:\n");
  LOG_ERROR("%s", "Tests ERROR");
  LOG_WARNING("%s", "Tests WARNING");
  LOG_DEBUG("%s", "Tests DEBUG");

  SET_LOG_LEVEL(DEBUG);
  SET_LOG_LOGGER_OUTPUT(CONSOLE_AND_FILE);
  printf("\nDEBUG level set and all messages printed:\n");
  LOG_ERROR("%s, %s, value: %d", "Tests ERROR", "Test text no. 2", 10);
  LOG_WARNING("%s, %s, value: %d", "Tests WARNING", "Test text no. 2", 8);
  LOG_DEBUG("%s, %s, value: %d", "Tests DEBUG", "Test text no. 2", 6);

  return 0;
}
```
## License

BSD 3-Clause License

***Copyright (c) 2022, Janusz Wolak***

All rights reserved.


