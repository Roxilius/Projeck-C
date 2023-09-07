#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define output_handle GetStdHandle(STD_OUTPUT_HANDLE)

void posisi(int x, int y)
{
COORD coordinate = {x, y};
SetConsoleCursorPosition(output_handle, coordinate);
}
void warna(int text, int background)
{
SetConsoleTextAttribute(output_handle,  background * 16 + text);
}
void pause()
{
system("pause>nul");
}

enum warna
{
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_AQUA,
    DARK_RED,
    DARK_PURPLE,
    BROWN,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    AQUA,
    RED,
    PURPLE,
    YELLOW,
    WHITE
};