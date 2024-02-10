#ifndef FORMAT_H
#define FORMAT_H

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define BLACK "\e[30m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define AQUA "\e[36m"
#define BRIGHT_GRAY "\e[37m"
#define GRAY "\e[90m"
#define BRIGHT_RED "\e[91m"
#define BRIGHT_GREEN "\e[92m"
#define BRIGHT_YELLOW "\e[93m"
#define BRIGHT_BLUE "\e[94m"
#define MAGENTA "\e[95m"
#define CYAN "\e[96m"
#define WHITE "\e[97m"
#define RESET "\e[0m"

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

//Set background to a diferent color
void changeBgColor(int selected_color)
{
    //A number between 40 - 47 or 100 - 107
    printf("\e[%dm", selected_color);
}

void clearOnKey()
{
    printf(WHITE "Presiona enter para continuar...");
    getch();
    printf("\e[1;1H\e[2J");
}
#endif