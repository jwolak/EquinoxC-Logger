cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_C_STANDARD 11)
project (EquinoxC-Logger)
set (SOURCE_FILES_DIR "../src")
add_executable(EquinoxC-Logger.x86

${SOURCE_FILES_DIR}/main.c

#headers
${SOURCE_FILES_DIR}/Logger.h
${SOURCE_FILES_DIR}/LoggerC-Level.h
${SOURCE_FILES_DIR}/LoggerC-Output.h

#source
${SOURCE_FILES_DIR}/Logger.c
${SOURCE_FILES_DIR}/LoggerC-Level.c
${SOURCE_FILES_DIR}/LoggerC-Output.c

)
