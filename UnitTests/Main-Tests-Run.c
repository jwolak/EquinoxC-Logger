#include "LoggerC-Console-Tests.c"
#include "LoggerC-Time-Tests.c"



// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(Log_Message_ERROR);
    RUN_TEST(Log_Message_DEBUG);
    RUN_TEST(Log_Message_WARNING);
    RUN_TEST(Get_Timestamp_Test);
    return UNITY_END();
}
