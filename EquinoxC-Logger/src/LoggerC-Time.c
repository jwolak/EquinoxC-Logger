/*
 * LoggerC-Time.c
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

#include "LoggerC-Time.h"

#include <stdio.h>
#include <time.h>
#include <string.h>

#define LOG_TIMESTAMP_LENGTH  150
#define TIMESTAMP_FORMAT    "%c"

static void get_timestamp(struct LoggerCTime *this, char* timestamp_ouput_buf) {

  char timestamp_buffer[LOG_TIMESTAMP_LENGTH];
  time_t time_now;
  struct tm *local_time = NULL;

  time(&time_now);
  local_time = localtime(&time_now);
  strftime(timestamp_buffer, sizeof(timestamp_buffer), TIMESTAMP_FORMAT, local_time);

  strncpy(timestamp_ouput_buf, timestamp_buffer, LOG_TIMESTAMP_LENGTH);
}

static struct LoggerCTime newLoggerCTime() {
  return (struct LoggerCTime) {.get_timestamp = &get_timestamp
                               };
}
const struct LoggerCTimeClass LoggerCTime={ .new = &newLoggerCTime };


