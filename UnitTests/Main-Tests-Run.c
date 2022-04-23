#include "LoggerC-Console-Tests.c"
#include "LoggerC-Time-Tests.c"
#include "LoggerC-File-Tests.c"
#include "LoggerC-Level-Tests.c"
#include "LoggerC-Output-Tests.c"
#include "LoggerC-Tests.c"

#include "unity.h"

void tearDown(void) {
  //remove("logs.log");
}

void setUp(void) {
    // set stuff up here
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(Log_Message_ERROR);
    RUN_TEST(Log_Message_DEBUG);
    RUN_TEST(Log_Message_WARNING);
    RUN_TEST(Get_Timestamp_Test);
    RUN_TEST(Log_ERROR_To_Log_File_Test);
    RUN_TEST(Log_WARNING_To_Log_File_Test);
    RUN_TEST(Log_DEBUG_To_Log_File_Test);
    RUN_TEST(Set_Logger_Level_To_ERROR);
    RUN_TEST(Set_Logger_Level_To_DEBUG);
    RUN_TEST(Set_Logger_Level_To_WARNING);
    RUN_TEST(Set_Logger_Level_To_DISABLED);
    RUN_TEST(Get_Logger_Level_Set_To_ERROR);
    RUN_TEST(Get_Logger_Level_Set_To_DEBUG);
    RUN_TEST(Get_Logger_Level_Set_To_WARNING);
    RUN_TEST(Get_Logger_Level_Set_To_DISBALED);
    RUN_TEST(Set_Logger_Output_To_CONSOLE);
    RUN_TEST(Set_Logger_Output_To_OUT_FILE);
    RUN_TEST(Set_Logger_Output_To_CONSOLE_AND_FILE);
    RUN_TEST(Get_Logger_Output_Set_To_CONSOLE);
    RUN_TEST(Get_Logger_Output_Set_To_OUT_FILE);
    RUN_TEST(Get_Logger_Output_Set_To_CONSOLE_AND_FILE);
    RUN_TEST(Set_LoggerC_Level_To_ERROR);
    RUN_TEST(Set_LoggerC_Level_To_WARNING);
    RUN_TEST(Set_LoggerC_Level_To_DEBUG);
    RUN_TEST(Set_LoggerC_Level_To_DISABLED);
    RUN_TEST(Set_LoggerC_Output_To_CONSOLE);
    RUN_TEST(Set_LoggerC_Output_To_OUT_FILE);
    RUN_TEST(Set_LoggerC_Output_To_CONSOLE_AND_FILE);
    RUN_TEST(Log_ERROR_Message_To_Console_And_ERROR_Level_Is_Set_And_Message_Is_Printed);
    RUN_TEST(Log_WARNING_Message_To_Console_And_Error_Level_Is_Set_And_Message_Is_NOT_Printed);
    RUN_TEST(Log_DEBUG_Message_To_Console_And_Error_Level_Is_Set_And_Message_Is_NOT_Printed);
    RUN_TEST(Log_ERROR_Message_To_Console_And_WARNING_Level_Is_Set_And_Message_Is_Printed);
    RUN_TEST(Log_WARNING_Message_To_Console_And_WARNING_Level_Is_Set_And_Message_Is_Printed);
    RUN_TEST(Log_DEBUG_Message_To_Console_And_WARNING_Level_Is_Set_And_Message_Is_NOT_Printed);
    RUN_TEST(Log_ERROR_Message_To_Console_And_DEBUG_Level_Is_Set_And_Message_Is_Printed);
    RUN_TEST(Log_WARNING_Message_To_Console_And_DEBUG_Level_Is_Set_And_Message_Is_Printed);
    RUN_TEST(Log_DEBUG_Message_To_Console_And_DEBUG_Level_Is_Set_And_Message_Is_Printed);
    RUN_TEST(Log_ERROR_Message_To_Console_And_DISABLED_Level_Is_Set_And_Message_Is_NOT_Printed);
    RUN_TEST(Log_WARNING_Message_To_Console_And_DISABLED_Level_Is_Set_And_Message_Is_NOT_Printed);
    RUN_TEST(Log_DEBUG_Message_To_Console_And_DISABLED_Level_Is_Set_And_Message_Is_NOT_Printed);
    return UNITY_END();
}
