// logger.cpp
#include "logger.h"

void Logger::Init(const LogConfig& conf) {
    //�Զ����sink
    loggerPtr = spdlog::rotating_logger_mt("base_logger", conf.path.c_str(), conf.size, conf.count);
    //���ø�ʽ
    //�μ��ĵ� https://github.com/gabime/spdlog/wiki/3.-Custom-formatting
    //[%Y-%m-%d %H:%M:%S.%e] ʱ��
    //[%l] ��־����
    //[%t] �߳�
    //[%s] �ļ�
    //[%#] �к�
    //[%!] ����
    //[%v] ʵ���ı�
    loggerPtr->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [thread %t] [%s %!:%#] %v");

    // ������־����
    loggerPtr->set_level(spdlog::level::from_str(conf.level));
    // ����ˢ����־����־���𣬵�����level����߼�����־ʱ������ˢ����־��  disk
    loggerPtr->flush_on(spdlog::level::from_str(conf.level));
}

/*
 * trace 0
 * debug 1
 * info 2
 * warn 3
 * error 4
 * critical 5
 * off 6 (not use)
 */
std::string Logger::GetLogLevel() {
    auto level = loggerPtr->level();
    return spdlog::level::to_string_view(level).data();
}

void Logger::SetLogLevel(const std::string& log_level) {
    auto level = spdlog::level::from_str(log_level);
    if (level == spdlog::level::off) {
        WARNLOG("Given invalid log level {}", log_level);
    }
    else {
        loggerPtr->set_level(level);
        loggerPtr->flush_on(level);
    }
}
