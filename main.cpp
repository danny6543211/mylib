#include <iostream>
#include "include/log.h"

int main()
{
    Logger logger("log.txt");
    
    logger.Log(LogLevel::INFO, "hello logger");

}