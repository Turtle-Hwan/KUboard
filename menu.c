#include "header.h"

void keySelectBtn(int* currentCursorY, int n, int X, int Y, int d) { //키보드 방향키로 메뉴 선택하는 함수
	// 현재 커서 Y위치 currentCursorY, 메뉴 개수 n, 1번 메뉴의 좌표 X, Y, 메뉴 간의 좌표 차 d
	int code2;
	code2 = _getch();
	if (code2 == 72 || code2 == 75) {//위 방향키//왼쪽 방향키
		if (*currentCursorY == Y) {
			gotoxy(X, Y);
			printf("  ");
			*currentCursorY = Y + (n - 1) * d;
			gotoxy(X, *currentCursorY);
			printf("▶");
		}
		else {
			gotoxy(X, *currentCursorY);
			printf("  ");
			*currentCursorY -= d;
			gotoxy(X, *currentCursorY);
			printf("▶");
		}
	}
	else if (code2 == 77 || code2 == 80) {//오른쪽 방향키//아래 방향키
		if (*currentCursorY == Y + (n - 1) * d) {
			gotoxy(X, *currentCursorY);
			printf("  ");
			*currentCursorY = Y;
			gotoxy(X, *currentCursorY);
			printf("▶");
		}
		else {
			gotoxy(X, *currentCursorY);
			printf("  ");
			*currentCursorY += d;
			gotoxy(X, *currentCursorY);
			printf("▶");
		}
	}
}

void selectLevelMenu() {
	system("cls");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 17);
	printf("****************************************\n"); //40칸
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 15);
	printf("*         난이도를 선택하세요          *\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 13);
	printf("****************************************\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 11);
	printf("             1. 고급\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 9);
	printf("             2. 중급\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 7);
	printf("             3. 초급\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 5);
	printf("             4. 돌아가기");

	gotoxy(CONSOLE_X / 2 - 14, CONSOLE_Y / 2 - 11);
	printf("▶");
	int code1, currentMenuY = CONSOLE_Y / 2 - 11; //현재 커서가 가리키는 메뉴의 y좌표 추가 값.
	int* CMYp = &currentMenuY;

	int level = 1; //레벨 설정 값.
	int* levelP = &level; //레벨 변수의 포인터
	while (1) {
		if (_kbhit()) {
			code1 = _getch();
			if (code1 == 224) {
				keySelectBtn(CMYp, 4, CONSOLE_X / 2 - 14, CONSOLE_Y / 2 - 11, 2);
			}
			else if (code1 == 13) {	//엔터 키 눌렸을 때
				if (currentMenuY == CONSOLE_Y / 2 - 11) {	//난이도 상
					level = 3;
					typingGame(levelP);
					break;
				}
				else if (currentMenuY == CONSOLE_Y / 2 - 9) {	//난이도 중
					level = 2;
					typingGame(levelP);
					break;
				}
				else if (currentMenuY == CONSOLE_Y / 2 - 7) {	//난이도 하
					level = 1;
					typingGame(levelP);
					break;
				}
				else    //돌아가기 버튼
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
	printf("****************************************\n"); //40칸
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 15);
	printf("*         캐릭터를 선택하세요          *\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 13);
	printf("****************************************\n");


	for (int i = 0; i < 14; i++) {
		gotoxy(CONSOLE_X / 2 - 10, CONSOLE_Y / 2 - 11 + i);
		printf("%s", C1[i]);

		gotoxy(CONSOLE_X / 2 - 10, CONSOLE_Y / 2 + 5 + i);
		printf("%s", C2[i]);
	}

	gotoxy(CONSOLE_X / 2 - 14, CONSOLE_Y / 2 - 11);
	printf("▶");
	int code1, currentMenuY = CONSOLE_Y / 2 - 11; //현재 커서가 가리키는 메뉴의 y좌표 추가 값.
	int* CMYp = &currentMenuY;
	while (1) {
		if (_kbhit()) {
			code1 = _getch();
			if (code1 == 224) {
				keySelectBtn(CMYp, 2, CONSOLE_X / 2 - 14, CONSOLE_Y / 2 - 11, 16);
			}
			else if (code1 == 13) {	//엔터 키 눌렸을 때
				if (currentMenuY == CONSOLE_Y / 2 - 11) {	//1번 공룡 캐릭
					selectCharacterNum = 1;
					break;
				}
				else if (currentMenuY == CONSOLE_Y / 2 + 5) {	//2번 쿠 캐릭
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
	printf("****************************************\n"); //40칸
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 15);
	printf("*               GAME OVER              *\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 13);
	printf("****************************************\n");

	//점수 띄워주기
	//이름 입력받기

}

void rankingMenu() {
	system("cls");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 17);
	printf("****************************************\n"); //40칸
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 15);
	printf("*               랭킹 기록              *\n");
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
	printf("▶        돌아가기");
	while (1) {
		if (_kbhit() && _getch() == 13) {
			break;
		}
	}

}


void pauseMenu(int* menu) {	// 게임 도중 esc 키 눌렀을 때 일시정지 화면
	system("cls");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 17);
	printf("****************************************\n"); //40칸
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 15);
	printf("*              일시 정지               *\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 13);
	printf("****************************************\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 9);
	printf("         1. 게임으로 돌아가기\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 5);
	printf("         2. 메인 화면으로 가기\n");

	gotoxy(CONSOLE_X / 2 - 17, CONSOLE_Y / 2 - 9);
	printf("▶");
	int code1, currentMenuY = CONSOLE_Y / 2 - 9; //현재 커서가 가리키는 메뉴의 y좌표 추가 값.
	int* CMYp = &currentMenuY;
	while (1) {
		if (_kbhit()) {
			code1 = _getch();
			if (code1 == 224) {
				keySelectBtn(CMYp, 2, CONSOLE_X / 2 - 17, CONSOLE_Y / 2 - 9, 4);
			}
			else if (code1 == 13) {	//엔터 키 눌렸을 때
				if (currentMenuY == CONSOLE_Y / 2 - 9) {	// 1. 게임으로 돌아가기
					*menu = 1;
					break;
				}
				else if (currentMenuY == CONSOLE_Y / 2 - 5) {	// 2. 메인 화면으로 가기
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
	printf("****************************************\n"); //40칸
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 15);
	printf("*            타자 연습 게임            *\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 13);
	printf("****************************************\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 11);
	printf("             1. 게임 시작\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 9);
	printf("             2. 랭킹 확인\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 7);
	printf("             3. 아이템 설명\n");
	gotoxy(CONSOLE_X / 2 - 20, CONSOLE_Y / 2 - 5);
	printf("             4. 게임종료\n");

	gotoxy(CONSOLE_X / 2 - 14, CONSOLE_Y / 2 - 11);
	printf("▶");
	int code1, currentMenuY = CONSOLE_Y / 2 - 11; //현재 커서가 가리키는 메뉴의 y좌표 추가 값.
	int* CMYp = &currentMenuY;
	while (1) {
		if (_kbhit()) {	//키보드가 눌렸다면 kbhit 1 반환.
			code1 = _getch();
			if (code1 == 224) {
				keySelectBtn(CMYp, 4, CONSOLE_X / 2 - 14, CONSOLE_Y / 2 - 11, 2);

			}
			else if (code1 == 13) {	//엔터 키 눌렸을 때
				if (currentMenuY == CONSOLE_Y / 2 - 11) {	//메뉴 1 : 게임
					//캐릭터 선택 메뉴
					selectCharacterMenu();
					//난이도 선택 메뉴 + 게임 시작 | 난이도 선택 후 게임 시작됨.
					selectLevelMenu();
					goto start;
				}
				else if (currentMenuY == CONSOLE_Y / 2 - 9) {	//메뉴 2 : 랭킹
					rankingMenu();	//랭킹 10개 까지만 화면 출력
					goto start;
				}
				else if (currentMenuY == CONSOLE_Y / 2 - 7)
				{
					itemExplain();
					goto start;
				}
				else if (currentMenuY == CONSOLE_Y / 2 - 5) {	//메뉴 3: 게임 종료
					break;
				}
			}
		}
	}
}
