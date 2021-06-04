// header.h에 void keySelectBtn(int* currentCursorY, int n, int X, int Y, int d) 추가
// void keySelectBtn() -> menu.c에 정의, menu.c - selectCharacterMenu()에서 사용 
// timeHeart.c - drawHeart() 

#include "header.h"

void drawHeart(int* i, int level) {  //typingGame()에서 부딪힐 때마다 i 중가, level에 따른 하트 개수 추가

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
				else if (c == 13) {
					if (retryMenu == CONSOLE_Y / 2 - 3) {
						mainMenu();
					}
					else if (retryMenu == CONSOLE_Y / 2 - 1) {
						goto b;
					}
				}
			}
		}
	}
}
