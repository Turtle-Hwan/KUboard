#include "header.h"
int level=0;

// 레벨 1 : 하  / 레벨 2 : 중 / 레벨 3 : 상

void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}  // 콘솔창 이동 // 콘솔창 이동

void Time(int Time)
{
	int count;

	if (Time < 10)
	{
		gotoxy(101, 0);
		printf("%d", Time);
	}
	else
	{
		gotoxy(100, 0);
		printf("%d", Time);
	}

	Sleep(1000);
	for (count = Time - 1; count > 0; count--)
	{
		int i;

		gotoxy(100, 0);
		printf(" ");
		gotoxy(101, 0);
		printf(" ");
		if (count < 10)
		{
			gotoxy(101, 0);
			printf("%d", count);
			Sleep(1000);
		}
		else
		{
			gotoxy(101, 0);
			printf("%d", count);
			Sleep(1000);
		}
	}
	if (level == 1 || level == 2)
	{
		if (count == 0)
		{
			level++;
			system("cls");
			Sleep(5000);
			typingGame(level);
		}
	}
	else
		mainMenu();
}  // 시간 타이머  // 시간 타이머


void color(char text[], int i) // *************색 추가*******************
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
	printf(text);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void drawHeart(int* i, int level) {  //typingGame()에서 부딪힐 때마다 i 중가, level에 따른 하트 개수 추가
//do {
	if (*i == 0) {
		gotoxy(10, 4); 
		color("♥ ♥ ♥ ♥ ♥", 4);
	}
	else if (*i == 1)
	{
		gotoxy(10, 4);
		color("♥ ♥ ♥ ♥ ♡", 4);
	}
	else if (*i == 2)
	{
		gotoxy(10, 4);
		color("♥ ♥ ♥ ♡ ♡", 4);
	}
	else if (*i == 3)
	{
		gotoxy(10, 4);
		color("♥ ♥ ♡ ♡ ♡", 4);
	}
	else if (*i == 4)
	{
		gotoxy(10, 4);
		color("♥ ♡ ♡ ♡ ♡", 4);
	}
	else
	{
		gotoxy(10, 4);
		color("♡ ♡ ♡ ♡ ♡", 4);

		int c, retryMenu = CONSOLE_Y / 2 - 3; //현재 커서가 가리키는 메뉴의 y좌표 추가 값.
		int* retry = &retryMenu;
		b:
		system("cls");
		gameOverMenu();
		gotoxy(CONSOLE_X / 2 - 10, CONSOLE_Y / 2 - 5);
		printf("돌아가시겠습니까?");
		gotoxy(CONSOLE_X / 2 - 3, CONSOLE_Y / 2 - 3);
		printf("Yes");
		gotoxy(CONSOLE_X / 2 - 3, CONSOLE_Y / 2 - 1);
		printf("No");

		gotoxy(CONSOLE_X / 2 - 6, CONSOLE_Y / 2 - 3);
		printf("▶");
		while (1) {
			if (_kbhit()) {
				c = _getch();
				if (c == 224) {
					keySelectBtn(retry, 2, CONSOLE_X / 2 - 6, CONSOLE_Y / 2 - 3, 2);
				}
				else if (c == 13) {	//엔터 키 눌렸을 때
					if (retryMenu == CONSOLE_Y / 2 - 3) {	//난이도 상
						mainMenu();
					}
					else if (retryMenu == CONSOLE_Y / 2 - 1) {	//난이도 중
						goto b;
					}
				}
			}
		}
		
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
