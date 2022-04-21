/*
 * LoggerC-File.c
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

#include "LoggerC-File.h"


#include <stdio.h>
#include <stdlib.h>

#define LOG_MSG_BUFFER_SIZE           3072
#define LOG_TIMESTAMP_LENGTH_TO_FILE  150
#define LOG_FILE_NAME                 "logs.log"
#define FILE_OPEN_MODE                "a"

static void log_message_to_file (struct LoggerCFile* this, enum LOG_LEVEL_TYPE message_type, char* message) {

  char log_message_buffer[LOG_MSG_BUFFER_SIZE];
  char timestamp_buffer[LOG_TIMESTAMP_LENGTH_TO_FILE];

  FILE *fd_log_file;

  fd_log_file = fopen(LOG_FILE_NAME, FILE_OPEN_MODE);

  if (fd_log_file == NULL) {
    printf("Failed to open/create log file!");
    exit(1);
  }

  switch (message_type) {
    case ERROR:
      this->loggerC_time.get_timestamp(&this->loggerC_time, timestamp_buffer);
      sprintf(log_message_buffer, "[%s] [ERROR]: %s\n", timestamp_buffer, message);
      fprintf(fd_log_file, "%s", log_message_buffer);
      break;

    case WARNING:
      this->loggerC_time.get_timestamp(&this->loggerC_time, timestamp_buffer);
      sprintf(log_message_buffer, "[%s] [WARNING]: %s\n", timestamp_buffer, message);
      fprintf(fd_log_file, "%s", log_message_buffer);
      break;

    case DEBUG:
      this->loggerC_time.get_timestamp(&this->loggerC_time, timestamp_buffer);
      sprintf(log_message_buffer, "[%s] [DEBUG]: %s\n", timestamp_buffer, message);
      fprintf(fd_log_file, "%s", log_message_buffer);
      break;
  }

  fclose(fd_log_file);

}

static struct LoggerCFile newLoggerCFile() {
  return (struct LoggerCFile) {.log_message_to_file = &log_message_to_file,
                               .loggerC_time = LoggerCTime.new()
                              };
}
const struct LoggerCFileClass LoggerCFile={ .new = &newLoggerCFile };

