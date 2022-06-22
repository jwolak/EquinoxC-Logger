/*
 * Logger.h
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

#ifndef SRC_LOGGERC_H_
#define SRC_LOGGERC_H_

#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

#include "LoggerC-Level.h"
#include "LoggerC-Output.h"
#include "LoggerC-Console.h"
#include "LoggerC-File.h"
#include "LoggerC-Super-Global-Instance-Counter.c"

static pthread_mutex_t instance_mutex = PTHREAD_MUTEX_INITIALIZER;

struct EquinoxCLogger {

  /* public */
  void (*set_logger_level)(struct EquinoxCLogger *this, enum LOG_LEVEL_TYPE logger_new_level);
  void (*set_logger_output)(struct EquinoxCLogger *this, enum LOG_OUTPUT_TYPE logger_new_output);
  void (*log_message_with_level_type)(struct EquinoxCLogger *this, enum LOG_LEVEL_TYPE logger_new_level, const char*, ...);

  /* private */
  pthread_mutex_t mutex;
  struct LoggerCLevel loggerC_level;
  struct LoggerCOutput loggerC_output;
  struct LoggerCConsole loggerC_console;
  struct LoggerCFile loggerC_file;
};

extern const struct EquinoxCLoggerClass {
  struct EquinoxCLogger (*new)();
} EquinoxCLogger;

struct EquinoxCLogger logger;

static void get_logger_instance() {

  pthread_mutex_lock(&instance_mutex);
  if (super_global_instance_counter == 0) {
    logger = EquinoxCLogger.new();
    ++super_global_instance_counter;
  }
  pthread_mutex_unlock(&instance_mutex);
}

#define SET_LOG_LEVEL(x) { get_logger_instance();\
                           pthread_mutex_lock(&logger.mutex);\
                           logger.set_logger_level(&logger, x);\
                           pthread_mutex_unlock(&logger.mutex);\
                          }

#define SET_LOG_LOGGER_OUTPUT(x) { get_logger_instance();\
                                   pthread_mutex_lock(&logger.mutex);\
                                   logger.set_logger_output(&logger, x);\
                                   pthread_mutex_unlock(&logger.mutex);\
                                  }


#define LOG_ERROR(x, ...) { get_logger_instance();\
                            pthread_mutex_lock(&logger.mutex);\
                            logger.log_message_with_level_type(&logger, ERROR, x, __VA_ARGS__);\
                            pthread_mutex_unlock(&logger.mutex);\
                           }


#define LOG_WARNING(x, ...) { get_logger_instance();\
                              pthread_mutex_lock(&logger.mutex);\
                              logger.log_message_with_level_type(&logger, WARNING, x, __VA_ARGS__);\
                              pthread_mutex_unlock(&logger.mutex);\
                             }

#define LOG_DEBUG(x, ...) { get_logger_instance();\
                            pthread_mutex_lock(&logger.mutex);\
                            logger.log_message_with_level_type(&logger, DEBUG, x, __VA_ARGS__);\
                            pthread_mutex_unlock(&logger.mutex);\
                           }

#endif /* SRC_LOGGERC_H_ */
