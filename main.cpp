#include <iostream>

 

class Log
{
public:
    enum LogLevel
    {
        LevelError = 0,
        LevelWarning,
        LevelInfo
    };
   
private:
    LogLevel m_LogLevel =  LogLevel::LevelError;
 
public:
    void SetLevel(LogLevel level)
    {
        m_LogLevel = level;
    }
    
    void PrintLog(const char* message)
    {
        char* levelTag;

        switch (m_LogLevel)
        {
            case LogLevel::LevelError:
                levelTag = "[Error]";
                break;

            case LogLevel::LevelWarning:
                levelTag = "[Warning]";
                break;

            case LogLevel::LevelInfo:
                levelTag = "[Info]";
                break;

            default:
                break;
        }
        
        std::cout << levelTag <<" " << message << std::endl;
    
    }

    void Error(const char* message)
    {
        return;
    }

};

int main()
{
    Log* log = new Log();

    log->SetLevel(Log::LevelError);
    log->PrintLog("Hellow");
    
    std::cin.get();
}