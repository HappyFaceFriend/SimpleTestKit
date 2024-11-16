#include <iostream>

struct LoggingEntity
{
    int x = 0;

    LoggingEntity()
    {
        std::cout << "LoggingEntity()" << std::endl;
    }
    LoggingEntity(int x) : x(x)
    {
        std::cout << "LoggingEntity(" << x << ")" << std::endl;
    }

    LoggingEntity(const LoggingEntity& other)
    {
        std::cout << "LoggingEntity(const LoggingEntity& other)" << std::endl;
        x = other.x;
    }

    LoggingEntity(LoggingEntity&& other) noexcept
    {
        std::cout << "LoggingEntity(LoggingEntity&& other)" << std::endl;
        x = other.x;
        other.x = 0;
    }

    LoggingEntity& operator=(const LoggingEntity& other)
    {
        std::cout << "operator=(const LoggingEntity& other)" << std::endl;
        if (this != &other)
        {
            x = other.x;
        }
        return *this;
    }

    LoggingEntity& operator=(LoggingEntity&& other) noexcept
    {
        std::cout << "operator=(LoggingEntity&& other)" << std::endl;
        if (this != &other)
        {
            x = other.x;
            other.x = 0;
        }
        return *this;
    }

    ~LoggingEntity()
    {
        std::cout << "~LoggingEntity(" << x << ")" << std::endl;
    }
};
