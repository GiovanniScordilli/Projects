#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>

enum Color
{
    blue    = 1,
    green   = 2,
    cyan    = 3,
    red     = 4,
    magenta = 5,
    yellow  = 6,
    reset   = 7
};

#ifdef _WIN32

#include <windows.h>

void colcout(std::string string, Color col);

#elif defined(__unix__) || defined(__unix) || defined(__APPLE__)



void            colcout(std::string string, Color col);
std::string     colorToStr(Color col);

#endif
#endif