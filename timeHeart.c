#include "header.h"
int level=0;

// ���� 1 : ��  / ���� 2 : �� / ���� 3 : ��

void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}  // �ܼ�â �̵� // �ܼ�â �̵�

//void Time(int Time)
//{
//	int count;
//
//	if (Time < 10)
//	{
//		gotoxy(101, 0);
//		printf("%d", Time);
//	}
//	else
//	{
//		gotoxy(100, 0);
//		printf("%d", Time);
//	}
//
//	Sleep(1000);
//	for (count = Time - 1; count > 0; count--)
//	{
//		int i;
//
//		gotoxy(100, 0);
//		printf(" ");
//		gotoxy(101, 0);
//		printf(" ");
//		if (count < 10)
//		{
//			gotoxy(101, 0);
//			printf("%d", count);
//			Sleep(1000);
//		}
//		else
//		{
//			gotoxy(101, 0);
//			printf("%d", count);
//			Sleep(1000);
//		}
//	}
//	if (level == 1 || level == 2)
//	{
//		if (count == 0)
//		{
//			level++;
//			system("cls");
//			Sleep(5000);
//			typingGame(level);
//		}
//	}
//	else
//		mainMenu();
//}  // �ð� Ÿ�̸�  // �ð� Ÿ�̸�


void color(char text[], int i) // *************�� �߰�*******************
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
	printf(text);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void drawHeart(int* i, int level) {  //typinggame()���� �ε��� ������ i �߰�, level�� ���� ��Ʈ ���� �߰�

	if (*i == 0) {
		gotoxy(10, 4); 
		color("�� �� �� �� ��", 4);
	}
	else if (*i == 1)
	{
		gotoxy(10, 4);
		color("�� �� �� �� ��", 4);
	}
	else if (*i == 2)
	{
		gotoxy(10, 4);
		color("�� �� �� �� ��", 4);
	}
	else if (*i == 3)
	{
		gotoxy(10, 4);
		color("�� �� �� �� ��", 4);
	}
	else if (*i == 4)
	{
		gotoxy(10, 4);
		color("�� �� �� �� ��", 4);
	}
	else
	{
		gotoxy(10, 4);
		color("�� �� �� �� ��", 4);


		int c, retrymenu = CONSOLE_Y / 2 - 3; //���� Ŀ���� ����Ű�� �޴��� y��ǥ �߰� ��.
		int* retry = &retrymenu;
		b:
		system("cls");
		gameOverMenu();
		gotoxy(CONSOLE_X / 2 - 10, CONSOLE_Y / 2 - 5);
		printf("���ư��ðڽ��ϱ�?");
		gotoxy(CONSOLE_X / 2 - 3, CONSOLE_Y / 2 - 3);
		printf("yes");
		gotoxy(CONSOLE_X / 2 - 3, CONSOLE_Y / 2 - 1);
		printf("no");

		gotoxy(CONSOLE_X / 2 - 6, CONSOLE_Y / 2 - 3);
		printf("��");
		while (1) {
			if (_kbhit()) {
				c = _getch();
				if (c == 224) {
					keySelectBtn(retry, 2, CONSOLE_X / 2 - 6, CONSOLE_Y / 2 - 3, 2);
				}
				else if (c == 13) {	//���� Ű ������ ��
					if (retrymenu == CONSOLE_Y / 2 - 3) {	//���̵� ��
						mainMenu();
					}
					else if (retrymenu == CONSOLE_Y / 2 - 1) {	//���̵� ��
						goto b;
					}
				}
			}
		}
		
	}
}   // �����   // heart("���ڿ�") -> ���ڿ��̶� �ٸ� �� ��Ʈ ����
