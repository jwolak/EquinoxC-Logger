/*
 * LoggerC-Level-Tests.c
 *
 *  Created on: 2022
 *      Author: Janusz Wolak
 */

/*-
 * BSD 3-Clause License
 *
 * Copyright (c) 2022, Janusz Wolak
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#include "unity.h"
#include <stdio.h>

#include "../EquinoxC-Logger/src/LoggerC-Level.c"

void Set_Logger_Level_To_ERROR() {

  struct LoggerCLevel loggerC_level = LoggerCLevel.new();
  loggerC_level.set_loggerC_level(&loggerC_level, ERROR);

  TEST_ASSERT_EQUAL(ERROR, loggerC_level.logger_level);
}

void Set_Logger_Level_To_DEBUG() {

  struct LoggerCLevel loggerC_level = LoggerCLevel.new();
  loggerC_level.set_loggerC_level(&loggerC_level, DEBUG);

  TEST_ASSERT_EQUAL(DEBUG, loggerC_level.logger_level);
}

void Set_Logger_Level_To_WARNING() {

  struct LoggerCLevel loggerC_level = LoggerCLevel.new();
  loggerC_level.set_loggerC_level(&loggerC_level, WARNING);

  TEST_ASSERT_EQUAL(WARNING, loggerC_level.logger_level);
}

void Set_Logger_Level_To_DISABLED() {

  struct LoggerCLevel loggerC_level = LoggerCLevel.new();
  loggerC_level.set_loggerC_level(&loggerC_level, DISABLED);

  TEST_ASSERT_EQUAL(DISABLED, loggerC_level.logger_level);
}


void Get_Logger_Level_Set_To_ERROR() {

  struct LoggerCLevel loggerC_level = LoggerCLevel.new();
  loggerC_level.logger_level = ERROR;

  TEST_ASSERT_EQUAL(ERROR, loggerC_level.get_loggerC_level(&loggerC_level));
}

void Get_Logger_Level_Set_To_DEBUG() {

  struct LoggerCLevel loggerC_level = LoggerCLevel.new();
  loggerC_level.logger_level = DEBUG;

  TEST_ASSERT_EQUAL(DEBUG, loggerC_level.get_loggerC_level(&loggerC_level));
}

void Get_Logger_Level_Set_To_WARNING() {

  struct LoggerCLevel loggerC_level = LoggerCLevel.new();
  loggerC_level.logger_level = WARNING;

  TEST_ASSERT_EQUAL(WARNING, loggerC_level.get_loggerC_level(&loggerC_level));
}

void Get_Logger_Level_Set_To_DISBALED() {

  struct LoggerCLevel loggerC_level = LoggerCLevel.new();
  loggerC_level.logger_level = DISABLED;

  TEST_ASSERT_EQUAL(DISABLED, loggerC_level.get_loggerC_level(&loggerC_level));
}

