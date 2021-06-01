#include "header.h"

void keySelectBtn(int* currentCursorY, int n, int X, int Y, int d) { //Ű���� ����Ű�� �޴� �����ϴ� �Լ�
	// ���� Ŀ�� Y��ġ currentCursorY, �޴� ���� n, 1�� �޴��� ��ǥ X, Y, �޴� ���� ��ǥ �� d
	int code2;
	code2 = _getch();
	if (code2 == 72 || code2 == 75) {//�� ����Ű//���� ����Ű
		if (*currentCursorY == Y) {
			gotoxy(X, Y);
			printf("  ");
			*currentCursorY = Y + (n - 1) * d;
			gotoxy(X, *currentCursorY);
			printf("��");
		}
		else {
			gotoxy(X, *currentCursorY);
			printf("  ");
			*currentCursorY -= d;
			gotoxy(X, *currentCursorY);
			printf("��");
		}
	}
	else if (code2 == 77 || code2 == 80) {//������ ����Ű//�Ʒ� ����Ű
		if (*currentCursorY == Y + (n - 1) * d) {
			gotoxy(X, *currentCursorY);
			printf("  ");
			*currentCursorY = Y;
			gotoxy(X, *currentCursorY);
			printf("��");
		}
		else {
			gotoxy(X, *currentCursorY);
			printf("  ");
			*currentCursorY += d;
			gotoxy(X, *currentCursorY);
			printf("��");
		}
	}
}

void selectLevelMenu() {
	system("cls");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 17);
	printf("****************************************\n"); //40ĭ
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 15);
	printf("*         ���̵��� �����ϼ���          *\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 13);
	printf("****************************************\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 11);
	printf("             1. ���\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 9);
	printf("             2. �߱�\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 7);
	printf("             3. �ʱ�\n");	
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 5);
	printf("             4. ���ư���");

	gotoxy(CONSOLE_X / 2 - 14, CONSOLE_Y / 2 - 11);
	printf("��");
	int code1, currentMenuY = CONSOLE_Y / 2 - 11; //���� Ŀ���� ����Ű�� �޴��� y��ǥ �߰� ��.
	int* CMYp = &currentMenuY;
	while (1) {
		if (_kbhit()) {
			code1 = _getch();
			if (code1 == 224) {
				keySelectBtn(CMYp, 4, CONSOLE_X / 2 - 14, CONSOLE_Y / 2 - 11, 2);
			}
			else if (code1 == 13) {	//���� Ű ������ ��
				if (currentMenuY == CONSOLE_Y / 2 - 11) {	//���̵� ��
					typingGame(3);
					break;
				}
				else if (currentMenuY == CONSOLE_Y / 2 - 9) {	//���̵� ��
					typingGame(2);
					break;
				}
				else if (currentMenuY == CONSOLE_Y / 2 - 7) {	//���̵� ��
					typingGame(1);
					break;
				}
				else    //���ư��� ��ư
					break;
			}
		}
	}
}

extern char C1[17][25], C2[17][25];
extern int selectCharacterNum;
void selectCharacterMenu() {
	system("cls");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 17);
	printf("****************************************\n"); //40ĭ
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 15);
	printf("*         ĳ���͸� �����ϼ���          *\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 13);
	printf("****************************************\n");


	for (int i = 0; i < 14; i++) {
		gotoxy(CONSOLE_X / 2 - 10, CONSOLE_Y / 2 - 11 + i);
		printf("%s", C1[i]);

		gotoxy(CONSOLE_X / 2 - 10, CONSOLE_Y / 2 + 5 + i);
		printf("%s", C2[i]);
	}

	gotoxy(CONSOLE_X / 2 - 14, CONSOLE_Y / 2 - 11);
	printf("��");
	int code1, currentMenuY = CONSOLE_Y / 2 - 11; //���� Ŀ���� ����Ű�� �޴��� y��ǥ �߰� ��.
	int* CMYp = &currentMenuY;
	while (1) {
		if (_kbhit()) {
			code1 = _getch();
			if (code1 == 224) {
				keySelectBtn(CMYp, 2, CONSOLE_X / 2 - 14, CONSOLE_Y / 2 - 11, 16);
			}
			else if (code1 == 13) {	//���� Ű ������ ��
				if (currentMenuY == CONSOLE_Y / 2 - 11) {	//1�� ���� ĳ��
					selectCharacterNum = 1;
					break;
				}
				else if (currentMenuY == CONSOLE_Y / 2 + 5) {	//2�� �� ĳ��
					selectCharacterNum = 2;
					break;
				}
			}
		}
	}
}


void gameOverMenu() {
	system("cls");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 17);
	printf("****************************************\n"); //40ĭ
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 15);
	printf("*               GAME OVER              *\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 13);
	printf("****************************************\n");

	//���� ����ֱ�
	//�̸� �Է¹ޱ�

}

void rankingMenu() {
	system("cls");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 17);
	printf("****************************************\n"); //40ĭ
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 15);
	printf("*               ��ŷ ���              *\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 13);
	printf("****************************************\n");
	
	char rank[10][12] = { 0, };
	checkRanking(rank);
	
	for (int i = 0; i < 10; i++) {
		gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 11 + i * 2);
		if (strlen(rank[i]) != 0) {
			printf("***            %s            ***", rank[i]);
		}
		else {
			printf("***                                  ***\n");
		}

	}

	gotoxy(CONSOLE_X / 2 - 14, CONSOLE_Y / 2 + 10);
	printf("��        ���ư���");
	while (1) {
		if (_kbhit() && _getch() == 13) {
			break;
		}
	}

}


void pauseMenu(int* menu) {	// ���� ���� esc Ű ������ �� �Ͻ����� ȭ��
	system("cls");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 17);
	printf("****************************************\n"); //40ĭ
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 15);
	printf("*              �Ͻ� ����               *\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 13);
	printf("****************************************\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 9);
	printf("         1. �������� ���ư���\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 5);
	printf("         2. ���� ȭ������ ����\n");

	gotoxy(CONSOLE_X / 2 - 17, CONSOLE_Y / 2 - 9);
	printf("��");
	int code1, currentMenuY = CONSOLE_Y / 2 - 9; //���� Ŀ���� ����Ű�� �޴��� y��ǥ �߰� ��.
	int* CMYp = &currentMenuY;
	while (1) {
		if (_kbhit()) {
			code1 = _getch();
			if (code1 == 224) {
				keySelectBtn(CMYp, 2, CONSOLE_X / 2 - 17, CONSOLE_Y / 2 - 9, 4);
			}
			else if (code1 == 13) {	//���� Ű ������ ��
				if (currentMenuY == CONSOLE_Y / 2 - 9) {	// 1. �������� ���ư���
					*menu = 1;
					break;
				}
				else if (currentMenuY == CONSOLE_Y / 2 - 5) {	// 2. ���� ȭ������ ����
					*menu = 2;
					break;
				}
			}
		}
	}
}




void mainMenu() {
start:
	system("cls");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 17);
	printf("****************************************\n"); //40ĭ
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 15);
	printf("*            Ÿ�� ���� ����            *\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 13);
	printf("****************************************\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 11);
	printf("             1. ���� ����\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 9);
	printf("             2. ��ŷ Ȯ��\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 7);
	printf("             3. ���� ����\n");

	gotoxy(CONSOLE_X / 2 - 14, CONSOLE_Y / 2 - 11);
	printf("��");
	int code1, currentMenuY = CONSOLE_Y / 2 - 11; //���� Ŀ���� ����Ű�� �޴��� y��ǥ �߰� ��.
	int* CMYp = &currentMenuY;
	while (1) {
		if (_kbhit()) {	//Ű���尡 ���ȴٸ� kbhit 1 ��ȯ.
			code1 = _getch();
			if (code1 == 224) {
				keySelectBtn(CMYp, 3, CONSOLE_X / 2 - 14, CONSOLE_Y / 2 - 11, 2);
				
			}
			else if (code1 == 13) {	//���� Ű ������ ��
				if (currentMenuY == CONSOLE_Y / 2 - 11) {	//�޴� 1 : ����
					//ĳ���� ���� �޴�
					selectCharacterMenu();
					//���̵� ���� �޴� + ���� ���� | ���̵� ���� �� ���� ���۵�.
					selectLevelMenu();
					goto start;
				}
				else if (currentMenuY == CONSOLE_Y / 2 - 9) {	//�޴� 2 : ��ŷ
					rankingMenu();	//��ŷ 10�� ������ ȭ�� ���
					goto start;
				}
				else if (currentMenuY == CONSOLE_Y / 2 - 7) {	//�޴� 3: ���� ����
					break;
				}
			}
		}
	}
}
