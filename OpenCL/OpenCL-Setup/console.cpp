#include "console.h"

#ifdef _WIN32

void colcout(std::string string, Color col)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, col);
    std::cout << string;
    SetConsoleTextAttribute(consoleHandle,  Color::reset);
}

#elif defined(__unix__) || defined(__unix) || defined(__APPLE__)

void colcout(std::string string, Color col)
{
    std::cout << colorToStr(col) + string + colorToStr(reset);
}

std::string colorToStr(Color col)
{
    std::string str {};

    switch (col)
    {
    case 1:
        str = "\033[0;34m";
        break;
    case 2:
        str = "\033[0;32m";
        break;
    case 3:
        str = "\033[0;36m";
        break;
    case 4:
        str = "\033[0;31m";
        break;
    case 5:
        str = "\033[0;35m";
        break;
    case 6:
        str = "\033[0;33m";
        break;
    case 7:
        str = "\033[0m";
        break;
    default:
        break;
    };

    return str;
}

#endif