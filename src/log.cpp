#include <iostream>
#include <fstream>
#include <ctime>
#include "log.h"

Logger::Logger(const std::string &filename)
{
    file.open(filename, std::ios::app);
}

Logger::~Logger()
{
    if (file.is_open())
        file.close();
}

void Logger::Log(LogLevel level, const std::string &message)
{
    std::string timestamp = GetTimestamp();
    std::string levelString = GetLogLevelString(level);
    std::string logLine = "[" + timestamp + "] " + "[" + levelString + "] " + message + "\n";

    std::cout << logLine; // 输出到控制台
    if (file.is_open())
        file << logLine; // 输出到日志文件
}

// 獲取時間字符串
std::string Logger::GetTimestamp()
{
    std::time_t now = std::time(nullptr);
    std::tm *tm = std::localtime(&now);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);

    return buffer;
}

// 獲取日誌等級字符串
std::string Logger::GetLogLevelString(LogLevel level)
{
    switch (level)
    {
    case LogLevel::DEBUG:
        return "DEBUG";
    case LogLevel::INFO:
        return "INFO";
    case LogLevel::WARNING:
        return "WARNING";
    case LogLevel::ERROR:
        return "ERROR";
    default:
        return "";
    }
}
