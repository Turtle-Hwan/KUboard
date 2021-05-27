#include "header.h"


// 레벨 1 : 하  / 레벨 2 : 중 / 레벨 3 : 상
#define LEVEL1 15

void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}  // 콘솔창 이동 // 콘솔창 이동

void Time()
{
	int count;
	if (LEVEL1 < 10)
	{
		gotoxy(1, 0);
		printf("%d", LEVEL1);
	}
	else
	{
		gotoxy(0, 0);
		printf("%d", LEVEL1);
	}
	
	Sleep(1000);
	for (count = LEVEL1 - 1; count > 0; count--)
	{
		gotoxy(0, 0);
		printf(" ");
		gotoxy(1, 0);
		printf(" ");
		if (count < 10)
		{
			gotoxy(1, 0);
			printf("%d", count);
			Sleep(1000);
		}
		else
		{
			gotoxy(0, 0);
			printf("%d", count);
			Sleep(1000);
		}
	}
}  // 시간 타이머  // 시간 타이머



void drawHeart(int* i, int level) {  //typingGame()에서 부딪힐 때마다 i 중가, level에 따른 하트 개수 추가

//do {
	if (*i == 0) {
		gotoxy(10, 4);
		printf("♥ ♥ ♥ ♥ ♥");
	}
	else if (*i == 1)
	{
		gotoxy(10, 4);
		printf("♥ ♥ ♥ ♥ ♡");
	}
	else if (*i == 2)
	{
		gotoxy(10, 4);
		printf("♥ ♥ ♥ ♡ ♡");
	}
	else if (*i == 3)
	{
		gotoxy(10, 4);
		printf("♥ ♥ ♡ ♡ ♡");
	}
	else if (*i == 4)
	{
		gotoxy(10, 4);
		printf("♥ ♡ ♡ ♡ ♡");
	}
	else
	{
		gotoxy(10, 4);
		printf("♡ ♡ ♡ ♡ ♡");
	}
//} while (i < 6);

	
//char a[20];
//int b, i = 0; // i = 틀린 횟수

//	gotoxy(3, 5);
//	printf("입력 : ");
//	gotoxy(10, 5);
//	printf("     ");
//	gotoxy(10, 5);
//	scanf("%s", &a);

}   // 생명력   // Heart("문자열") -> 문자열이랑 다를 시 하트 깍임
