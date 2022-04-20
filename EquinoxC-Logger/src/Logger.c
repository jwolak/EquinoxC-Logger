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

static struct EquinoxCLogger* get_instance(struct EquinoxCLogger *this) {

  printf("%s", "get_instance_called\n");

  pthread_mutex_lock(&this->mutex);
  if (this->equinoxc_logger_instance == NULL) {
    this->equinoxc_logger_instance = malloc(sizeof(struct EquinoxCLogger));
  }
  pthread_mutex_unlock(&this->mutex);

  return this->equinoxc_logger_instance;
}

static void set_logger_level(struct EquinoxCLogger *this, enum LOG_LEVEL_TYPE logger_new_level ) {

  printf("%s\n", "Set logger level");
  this->logger_level = logger_new_level;
}

static enum LOG_LEVEL_TYPE get_logger_level(struct EquinoxCLogger *this) {

  printf("%s\n", "Get logger level");
  return this->logger_level;
}

static void set_logger_output(struct EquinoxCLogger *this, enum LOG_OUTPUT_TYPE logger_new_output) {

  this->logger_output = logger_new_output;
}

static enum LOG_OUTPUT_TYPE get_logger_output(struct EquinoxCLogger *this) {

  return this->logger_output;
}

static struct EquinoxCLogger new() {
  printf("%s", "Object created\n");
  return (struct EquinoxCLogger) {.get_logger_level = &get_logger_level,
                                  .set_logger_level = &set_logger_level,
                                  .mutex = PTHREAD_MUTEX_INITIALIZER};
}
const struct EquinoxCLoggerClass EquinoxCLogger={ .new = &new };

