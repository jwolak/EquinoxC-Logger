cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_C_STANDARD 11)
set (SOURCE_FILES_DIR "../src")

add_library(EquinoxCLogger STATIC

#headers
${SOURCE_FILES_DIR}/LoggerC.h
${SOURCE_FILES_DIR}/LoggerC-Level.h
${SOURCE_FILES_DIR}/LoggerC-Output.h
${SOURCE_FILES_DIR}/LoggerC-Console.h
${SOURCE_FILES_DIR}/LoggerC-Time.h
${SOURCE_FILES_DIR}/LoggerC-File.h

#source
${SOURCE_FILES_DIR}/LoggerC.c
${SOURCE_FILES_DIR}/LoggerC-Level.c
${SOURCE_FILES_DIR}/LoggerC-Output.c
${SOURCE_FILES_DIR}/LoggerC-Console.c
${SOURCE_FILES_DIR}/LoggerC-Time.c
${SOURCE_FILES_DIR}/LoggerC-File.c

)
