/*
 * Logger.c
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

#include "Logger.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define LOG_MESSAGE_BUFFER_SIZE 2048

static void set_logger_level(struct EquinoxCLogger *this, enum LOG_LEVEL_TYPE logger_new_level ) {

  printf("%s\n", "Set logger level");
  this->loggerC_level.set_loggerC_level(&this->loggerC_level, logger_new_level);
}

static void set_logger_output(struct EquinoxCLogger *this, enum LOG_OUTPUT_TYPE logger_new_output) {

  printf("%s\n", "Set logger output");
  this->loggerC_output.set_loggerC_output(&this->loggerC_output, logger_new_output);
}

static void log_message_with_level_type (struct EquinoxCLogger *this, enum LOG_LEVEL_TYPE logger_new_level, const char* format, ...) {

  enum LOG_LEVEL_TYPE current_set_logger_level = this->loggerC_level.get_loggerC_level(&this->loggerC_level);


  if (logger_new_level <= current_set_logger_level) {

    va_list argp;
    char log_message_buffer[LOG_MESSAGE_BUFFER_SIZE] = { 0 };
    va_start(argp, format);

    vsnprintf(log_message_buffer, sizeof(log_message_buffer), format, argp);
    enum LOG_OUTPUT_TYPE log_output_type = this->loggerC_output.get_loggerC_output(&this->loggerC_output);

    switch (log_output_type) {
      case CONSOLE:
        this->loggerC_console.log_message(&this->loggerC_console, current_set_logger_level, log_message_buffer);
        break;

      case OUT_FILE:
        this->loggerC_file.log_message_to_file(&this->loggerC_file, current_set_logger_level, log_message_buffer);
        break;

      case CONSOLE_AND_FILE:
      default:
        this->loggerC_console.log_message(&this->loggerC_console, current_set_logger_level, log_message_buffer);
        this->loggerC_file.log_message_to_file(&this->loggerC_file, current_set_logger_level, log_message_buffer);
        break;
    }

    va_end(argp);
  }
}

static struct EquinoxCLogger new() {
  printf("%s", "Object created\n");
  return (struct EquinoxCLogger) {.set_logger_output = &set_logger_output,
                                  .set_logger_level = &set_logger_level,
                                  .mutex = PTHREAD_MUTEX_INITIALIZER,
                                  .log_message_with_level_type = &log_message_with_level_type,
                                  .loggerC_level = LoggerCLevel.new(),
                                  .loggerC_output = LoggerCOutput.new(),
                                  .loggerC_console = LoggerCConsole.new(),
                                  .loggerC_file = LoggerCFile.new()
                                  };
}
const struct EquinoxCLoggerClass EquinoxCLogger={ .new = &new };

