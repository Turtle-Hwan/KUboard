#include "header.h"

void ITEM() {
	gotoxy(CONSOLE_X / 2 + 60, CONSOLE_Y / 2 - 17);
	color(" < ������ >", 5);
	gotoxy(CONSOLE_X / 2 + 65, CONSOLE_Y / 2 - 15);
	printf("��");
	gotoxy(CONSOLE_X / 2 + 60, CONSOLE_Y / 2 - 13);
	printf("1 ���� ���!!");
}


void itemExplainMenu() {

		system("cls");
		gotoxy(35, 10);
		printf("1. �������� ( ���� �ʱ�ȭ, 2�� ����, �ܾ� �Ҹ�, ��Ʈ ���� )�� �ֽ��ϴ�.\n\n");
		gotoxy(35, 13);
		printf("2. ������ Ű(���� 1)�� 100�� �������� Ȱ��ȭ �Ǹ�, ��ø�� �˴ϴ�. ( �� -> �� )\n\n");
		gotoxy(35, 16);
		printf("3. �ܾ� �Ҹ��� Ȱ��ȭ �Ǿ� �ܾ �������, ������� ���� �ܾ ����� �Է��ϸ� ������ �ݿ��� �˴ϴ�. ");

		gotoxy(CONSOLE_X / 2 - 14, CONSOLE_Y / 2 + 10);
		printf("��        ���ư���");
		while (1) {
			if (_kbhit() && _getch() == 13) {
				break;
			}
		}
}
