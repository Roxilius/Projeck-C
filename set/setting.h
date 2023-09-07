#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

#define outputHandle GetStdHandle(STD_OUTPUT_HANDLE)
#define BLACK 0x0
#define DARK_BLUE 0x1
#define DARK_GREEN 0x2
#define DARK_CYAN 0x3
#define DARK_RED 0x4
#define DARK_PURPLE 0x5
#define DARK_YELLOW 0x6
#define DARK_WHITE 0x7
#define GRAY 0x8
#define BLUE 0x9
#define GREEN 0xa
#define CYAN 0xb
#define RED 0xc
#define PURPLE 0xd
#define YELLOW 0xe
#define WHITE 0xf

int text_color = FOREGROUND_INTENSITY;
int bg_color = 0;

void posisi(SHORT x, SHORT y)
{
    COORD position = {x, y};
    SetConsoleCursorPosition(outputHandle, position);
}

void warna(int color)
{
    SetConsoleTextAttribute(outputHandle, color | (bg_color << 4));
    text_color = color;
}

void background(int color)
{
    SetConsoleTextAttribute(outputHandle, text_color | (color << 4));
    bg_color = color;
}

void bingkaii(int x, int y, int panjang, int lebar, int color, int bg, int ascii){
    for (int i = 0; i <= panjang; i++){
        for (int j = 0; j <= lebar; j++){
            if ( i == 0 || i == panjang || j == 0 || j == lebar ){
                posisi(i+x,j+y); warna(color); printf("%c",ascii);
            }
            else{
                posisi(i+x,j+y); background(bg); printf(" ");
            }
        }
    }
}