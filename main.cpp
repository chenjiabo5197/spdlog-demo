//#include "spdlog/spdlog.h"
//#include "spdlog/cfg/env.h" 
//#include "spdlog/sinks/basic_file_sink.h"
//#include "spdlog/sinks/rotating_file_sink.h"
//
//
//#include <iostream>
//
//using namespace std;
//using namespace spdlog;
//
//int main()
//{
//    // Create a file rotating logger with 5mb size max and 3 rotated files.
//    auto rotating_logger_a = spdlog::rotating_logger_mt("mainlogger", "logs/test.log", 1024 * 1024 * 5, 3);
//
//    // testing 
//    for (int i = 0; i < 1024 * 10; i++)
//    {
//        rotating_logger_a->info("index = {}", i);
//
//        cout << "index = " << i << endl;
//    }
//
//    spdlog::shutdown();
//
//    system("pause");
//    return 0;
//}
#include "logger.h"

int main()
{
    // 定义日志配置项
    LogConfig conf = {
        "trace",
        "logs/test.log",
        5 * 1024 * 1024,
        10
    };
    INITLOG(conf);
    // 日志初始级别为trace
    TRACELOG("current log level is {}", GETLOGLEVEL());
    TRACELOG("this is trace log");
    DEBUGLOG("this is debug log");
    INFOLOG("this is info log");
    WARNLOG("this is warning log");
    ERRORLOG("this is a error log");
    CRITICALLOG("this is critical log");

    // 改为warning级别后，trace、debug、info级别日志不会输出了
    SETLOGLEVEL("warn");
    WARNLOG("after set log level to warning");
    TRACELOG("this is trace log");
    DEBUGLOG("this is debug log");
    INFOLOG("this is info log");
    WARNLOG("this is warning log");
    ERRORLOG("this is a error log");
    CRITICALLOG("this is critical log");

    return 0;
}




