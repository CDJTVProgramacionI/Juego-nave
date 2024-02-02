#ifndef FORMAT_H
#define FORMAT_H

#include <stdio.h>
#include <Windows.h>

typedef enum
{
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    PURPLE = 35,
    AQUA = 36,
    BRIGHT_GRAY = 37,
    GRAY = 90,
    BRIGHT_RED = 91,
    BRIGHT_GREEN = 92,
    BRIGHT_YELLOW = 93,
    BRIGHT_BLUE = 94,
    MAGENTA = 95,
    CYAN = 96,
    WHITE = 97
} color;

static HANDLE stdoutHandle;
static DWORD outModeInit;
void setupConsole() 
{
    DWORD outMode = 0;
    stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    if(stdoutHandle == INVALID_HANDLE_VALUE) {
        exit(GetLastError());
    }
    
    if(!GetConsoleMode(stdoutHandle, &outMode)) {
        exit(GetLastError());
    }

    outModeInit = outMode;
    
    // Enable ANSI escape codes
    outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if(!SetConsoleMode(stdoutHandle, outMode)) {
        exit(GetLastError());
    }   
}

//Show all the posible colors
void testAllColors()
{
    int color_index;

    for(color_index = 30; color_index <= 37; color_index++)
    {
        printf("\e[%dm         \e[%d;40m TEXTO DE PRUEBA\n", color_index + 10, color_index);
    }

    for(color_index = 90; color_index <= 97; color_index++)
    {
        printf("\e[%dm         \e[%d;40m TEXTO DE PRUEBA\n", color_index + 10, color_index);
    }
}

//Set text to a diferent color
void changeTextColor(color selected_color)
{
    printf("\e[%dm", selected_color);
}

//Set background to a diferent color
void changeBgColor(color selected_color)
{
    //selected color is intended for text
    //adding 10 we select the background instead of text
    color backgroundColor = selected_color + 10;
    printf("\e[%dm", backgroundColor);
}

//Black BG color, white text color
void resetFormat()
{
    printf("\e[0m"); 
}
#endif