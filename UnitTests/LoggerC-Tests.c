/*
 * LoggerC-Tests.c
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

#include "../EquinoxC-Logger/src/LoggerC.c"

#define ERROR_TEST_MESSAGE "LoggerC Error test message"
#define WARNING_TEST_MESSAGE "LoggerC Warning test message"
#define DEBUG_TEST_MESSAGE "LoggerC Debug test message"

void Set_LoggerC_Level_To_ERROR() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();
  equinoxC_logger.set_logger_level(&equinoxC_logger, ERROR);

  TEST_ASSERT_EQUAL(ERROR, equinoxC_logger.loggerC_level.logger_level);
}

void Set_LoggerC_Level_To_WARNING() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();
  equinoxC_logger.set_logger_level(&equinoxC_logger, WARNING);

  TEST_ASSERT_EQUAL(WARNING, equinoxC_logger.loggerC_level.logger_level);
}

void Set_LoggerC_Level_To_DEBUG() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();
  equinoxC_logger.set_logger_level(&equinoxC_logger, DEBUG);

  TEST_ASSERT_EQUAL(DEBUG, equinoxC_logger.loggerC_level.logger_level);
}

void Set_LoggerC_Level_To_DISABLED() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();
  equinoxC_logger.set_logger_level(&equinoxC_logger, DISABLED);

  TEST_ASSERT_EQUAL(DISABLED, equinoxC_logger.loggerC_level.logger_level);
}


void Set_LoggerC_Output_To_CONSOLE() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();
  equinoxC_logger.set_logger_output(&equinoxC_logger, CONSOLE);

  TEST_ASSERT_EQUAL(CONSOLE, equinoxC_logger.loggerC_output.logger_output);
}

void Set_LoggerC_Output_To_OUT_FILE() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();
  equinoxC_logger.set_logger_output(&equinoxC_logger, OUT_FILE);

  TEST_ASSERT_EQUAL(OUT_FILE, equinoxC_logger.loggerC_output.logger_output);
}

void Set_LoggerC_Output_To_CONSOLE_AND_FILE() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();
  equinoxC_logger.set_logger_output(&equinoxC_logger, CONSOLE_AND_FILE);

  TEST_ASSERT_EQUAL(CONSOLE_AND_FILE, equinoxC_logger.loggerC_output.logger_output);
}

void Log_ERROR_Message_To_Console_And_ERROR_Level_Is_Set_And_Message_Is_Printed() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();

  equinoxC_logger.loggerC_level.logger_level = ERROR;
  equinoxC_logger.loggerC_output.logger_output = CONSOLE_AND_FILE;
  equinoxC_logger.log_message_with_level_type(&equinoxC_logger, ERROR, "%s", ERROR_TEST_MESSAGE);
}

void Log_WARNING_Message_To_Console_And_Error_Level_Is_Set_And_Message_Is_NOT_Printed() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();

  equinoxC_logger.loggerC_level.logger_level = ERROR;
  equinoxC_logger.loggerC_output.logger_output = CONSOLE_AND_FILE;
  equinoxC_logger.log_message_with_level_type(&equinoxC_logger, WARNING, "%s", WARNING_TEST_MESSAGE);
}

void Log_DEBUG_Message_To_Console_And_Error_Level_Is_Set_And_Message_Is_NOT_Printed() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();

  equinoxC_logger.loggerC_level.logger_level = ERROR;
  equinoxC_logger.loggerC_output.logger_output = CONSOLE_AND_FILE;
  equinoxC_logger.log_message_with_level_type(&equinoxC_logger, DEBUG, "%s", DEBUG_TEST_MESSAGE);
}

void Log_ERROR_Message_To_Console_And_WARNING_Level_Is_Set_And_Message_Is_Printed() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();

  equinoxC_logger.loggerC_level.logger_level = WARNING;
  equinoxC_logger.loggerC_output.logger_output = CONSOLE_AND_FILE;
  equinoxC_logger.log_message_with_level_type(&equinoxC_logger, ERROR, "%s", ERROR_TEST_MESSAGE);
}

void Log_WARNING_Message_To_Console_And_WARNING_Level_Is_Set_And_Message_Is_Printed() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();

  equinoxC_logger.loggerC_level.logger_level = WARNING;
  equinoxC_logger.loggerC_output.logger_output = CONSOLE_AND_FILE;
  equinoxC_logger.log_message_with_level_type(&equinoxC_logger, WARNING, "%s", WARNING_TEST_MESSAGE);
}

void Log_DEBUG_Message_To_Console_And_WARNING_Level_Is_Set_And_Message_Is_NOT_Printed() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();

  equinoxC_logger.loggerC_level.logger_level = WARNING;
  equinoxC_logger.loggerC_output.logger_output = CONSOLE_AND_FILE;
  equinoxC_logger.log_message_with_level_type(&equinoxC_logger, DEBUG, "%s", DEBUG_TEST_MESSAGE);
}

void Log_ERROR_Message_To_Console_And_DEBUG_Level_Is_Set_And_Message_Is_Printed() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();

  equinoxC_logger.loggerC_level.logger_level = DEBUG;
  equinoxC_logger.loggerC_output.logger_output = CONSOLE_AND_FILE;
  equinoxC_logger.log_message_with_level_type(&equinoxC_logger, ERROR, "%s", ERROR_TEST_MESSAGE);
}

void Log_WARNING_Message_To_Console_And_DEBUG_Level_Is_Set_And_Message_Is_Printed() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();

  equinoxC_logger.loggerC_level.logger_level = DEBUG;
  equinoxC_logger.loggerC_output.logger_output = CONSOLE_AND_FILE;
  equinoxC_logger.log_message_with_level_type(&equinoxC_logger, WARNING, "%s", WARNING_TEST_MESSAGE);
}

void Log_DEBUG_Message_To_Console_And_DEBUG_Level_Is_Set_And_Message_Is_Printed() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();

  equinoxC_logger.loggerC_level.logger_level = DEBUG;
  equinoxC_logger.loggerC_output.logger_output = CONSOLE_AND_FILE;
  equinoxC_logger.log_message_with_level_type(&equinoxC_logger, DEBUG, "%s", DEBUG_TEST_MESSAGE);
}

void Log_ERROR_Message_To_Console_And_DISABLED_Level_Is_Set_And_Message_Is_NOT_Printed() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();

  equinoxC_logger.loggerC_level.logger_level = DISABLED;
  equinoxC_logger.loggerC_output.logger_output = CONSOLE_AND_FILE;
  equinoxC_logger.log_message_with_level_type(&equinoxC_logger, ERROR, "%s", ERROR_TEST_MESSAGE);
}

void Log_WARNING_Message_To_Console_And_DISABLED_Level_Is_Set_And_Message_Is_NOT_Printed() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();

  equinoxC_logger.loggerC_level.logger_level = DISABLED;
  equinoxC_logger.loggerC_output.logger_output = CONSOLE_AND_FILE;
  equinoxC_logger.log_message_with_level_type(&equinoxC_logger, WARNING, "%s", WARNING_TEST_MESSAGE);
}

void Log_DEBUG_Message_To_Console_And_DISABLED_Level_Is_Set_And_Message_Is_NOT_Printed() {

  struct EquinoxCLogger equinoxC_logger = EquinoxCLogger.new();

  equinoxC_logger.loggerC_level.logger_level = DISABLED;
  equinoxC_logger.loggerC_output.logger_output = CONSOLE_AND_FILE;
  equinoxC_logger.log_message_with_level_type(&equinoxC_logger, DEBUG, "%s", DEBUG_TEST_MESSAGE);
}
