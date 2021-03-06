/*
 * LoggerC-Console.c
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

#include "LoggerC-Console.h"

#include <stdio.h>
#include <string.h>

#define LOG_MSG_BUFFER_SIZE               3072
#define LOG_TIMESTAMP_LENGTH_TO_CONSOLE   150

static void log_message (struct LoggerCConsole* this, enum LOG_LEVEL_TYPE message_type, char* message) {

  char log_message_buffer[LOG_MSG_BUFFER_SIZE];
  char timestamp_buffer[LOG_TIMESTAMP_LENGTH_TO_CONSOLE];

  switch (message_type) {
    case ERROR:
      this->loggerC_time.get_timestamp(&this->loggerC_time, timestamp_buffer);
      sprintf(log_message_buffer, "[%s] [ERROR]: %s", timestamp_buffer, message);
      break;

    case WARNING:
      this->loggerC_time.get_timestamp(&this->loggerC_time, timestamp_buffer);
      sprintf(log_message_buffer, "[%s] [WARNING]: %s", timestamp_buffer, message);
      break;

    case DEBUG:
      this->loggerC_time.get_timestamp(&this->loggerC_time, timestamp_buffer);
      sprintf(log_message_buffer, "[%s] [DEBUG]: %s", timestamp_buffer, message);
      break;
  }

  fprintf(stdout, "%s\n", log_message_buffer);

}

static struct LoggerCConsole new() {
  return (struct LoggerCConsole) {.log_message = &log_message,
                                  .loggerC_time = LoggerCTime.new()
                                 };
}
const struct LoggerCConsoleClass LoggerCConsole={ .new = &new };

