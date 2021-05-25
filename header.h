#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>

//consoleInfo의 가로, 세로
#define CONSOLE_X 150
#define CONSOLE_Y 50

void gotoxy(int x, int y);	//timeHeart.c에 선언, 온갖곳에서 사용
void consoleInfo();			//typingGame.c에 선언, main() 에서 사용

void mainMenu();			//menu.c에 선언, main() 에서 사용

void checkRanking(char ranking[][11]);	//rank.c에 선언, menu.c -> rankingMenu() 에서 사용