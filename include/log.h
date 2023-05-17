/*
    include log.h 後
    編譯時記得加上 -L{庫文件夾} -llog選項
*/
#ifndef LOG_H
#define LOG_H

#include <string>
#include <fstream>

// 日誌等級
enum class LogLevel { DEBUG, INFO, WARNING, ERROR };

class Logger {
public:
    Logger(const std::string& filename);
    ~Logger();
    // 使用LogLevel選擇日誌等級 message選擇日誌信息
    void Log(LogLevel level, const std::string& message);
private:
    std::ofstream file;
    // 獲取當前時間字符串
    std::string GetTimestamp();
    // 獲取日誌等級字符串
    std::string GetLogLevelString(LogLevel level);
};

#endif