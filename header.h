#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>

//consoleInfo�� ����, ����
#define CONSOLE_X 150
#define CONSOLE_Y 50

void gotoxy(int x, int y);	//timeHeart.c�� ����, �°������� ���
void consoleInfo();			//typingGame.c�� ����, main() ���� ���

void mainMenu();			//menu.c�� ����, main() ���� ���

void checkRanking(char ranking[][11]);	//rank.c�� ����, menu.c -> rankingMenu() ���� ���