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
