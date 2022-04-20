/*
 * main.c
 *
 *  Created on: 2022
 *      Author: Janusz Wolak
 */

/*-
 * Copyright (c) 2022 Janusz Wolak
 * All rights reserved.
 *
 */

#include <stdio.h>
#include "Logger.h"

int main() {

  SET_LOG_LEVEL(ERROR);
  SET_LOG_LOGGER_OUTPUT(CONSOLE_AND_FILE);
  LOG_ERROR("%s", "Tests");
  LOG_WARNING("%s", "Tests");
  LOG_DEBUG("%s", "Tests");

    return 0;
}
