#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

//consoleInfo�� ����, ����
#define CONSOLE_X 150
#define CONSOLE_Y 50

//���ܾ� �ִ� ����
#define WORD_MAXLEN 30


void gotoxy(int x, int y);	//timeHeart.c�� ����, �°������� ���
//void consoleInfo();			//typingGame.c�� ����, main() ���� ���

void mainMenu();			//menu.c�� ����, main() ���� ���

void checkRanking(char ranking[][12]);	//rank.c�� ����, menu.c -> rankingMenu() ���� ���



void typingGame(int level); //typingGame.c�� ����, menu -> selectLevelMenu() ���� ���
void drawHeart(int* i, int level); //timeHeart.c ���� , typingGame()�� ���


// ���ܾ�� ���� ���Ե� || ���̵� �� : 6�ڸ� ���� (947�����) || ���̵� �� : 7~9�ڸ� (2075�����) || ���̵� �� : (2940�����)
