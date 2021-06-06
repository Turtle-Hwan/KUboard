#include "header.h"

void ITEM() {
	gotoxy(CONSOLE_X / 2 + 60, CONSOLE_Y / 2 - 17);
	color(" < 아이템 >", 5);
	gotoxy(CONSOLE_X / 2 + 65, CONSOLE_Y / 2 - 15);
	printf("○");
	gotoxy(CONSOLE_X / 2 + 60, CONSOLE_Y / 2 - 13);
	printf("1 눌러 사용!!");
}


void itemExplainMenu() {

		system("cls");
		gotoxy(35, 10);
		printf("1. 아이템은 ( 문자 초기화, 2초 정지, 단어 소멸, 하트 증가 )가 있습니다.\n\n");
		gotoxy(35, 13);
		printf("2. 아이템 키(숫자 1)은 100점 간격으로 활성화 되며, 중첩이 됩니다. ( ○ -> ● )\n\n");
		gotoxy(35, 16);
		printf("3. 단어 소멸이 활성화 되어 단어가 사라져도, 사라지기 전의 단어를 기억해 입력하면 점수에 반영이 됩니다. ");

		gotoxy(CONSOLE_X / 2 - 14, CONSOLE_Y / 2 + 10);
		printf("▶        돌아가기");
		while (1) {
			if (_kbhit() && _getch() == 13) {
				break;
			}
		}
}
