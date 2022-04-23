#include "LoggerC-Console-Tests.c"
#include "LoggerC-Time-Tests.c"
#include "LoggerC-File-Tests.c"
#include "LoggerC-Level-Tests.c"



// not needed when using generate_test_runner.rb
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
    return UNITY_END();
}
