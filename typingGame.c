﻿#include "header.h"

#define GROUND_Y CHARACTER_Y+14

#define OBSTACLE_START_X 137 //장애물 초기 x 좌표
#define OBSTACLE_Y 26

#define CHARACTER_Y 19
#define CHARACTER_X 17


int selectCharacterNum;	//몇 번 캐릭터 선택했는지
char C1[17][25] = {
	"                \n",
	"         $$$$$$ \n",
	"       $$ $$$$$$\n",
	"       $$$$$$$$$\n",
	"$      $$$      \n",
	"$$      $$$$$$$ \n",
	"$$      $$$$$   \n",
	"$$$   $$$$$$    \n",
	" $$  $$$$$$$$$$$\n",
	" $$$$$$$$$$$    \n",
	"  $$$$$$$$$$    \n",
	"    $$$$$$$$    \n",
	"     $$$$$$     \n",
	"     $    $     \n",
	"     $$   $$    \n"

};
char C2[17][25] = {	//14줄
	"    :.   ..   .:    \n",
	"    | '- ;; -' |    \n",
	" , -            - , \n",
	"   :   !_  _!   :   \n",
	"    :    --    :    \n",
	"   : -        - :   \n",
	"     -___  ___-     \n",
	"    ,-:* KU *:-,    \n",
	"   | :   ''   : |   \n",
	"   | :        : |  ,\n",
	"   (_ : -  - : _) ! \n",
	"      :  ,,  :   !  \n",
	"     _|  ,,  |_ !   \n",
	"    !____!!____!    \n"
};

void drawCharacter1(int characterY, bool leg) {
	gotoxy(0, characterY);

	for (int i = 0; i < 12; i++) {
		printf("%s", C1[i]);
	}

	if (leg) {
		printf("     $    $$$    \n");
		printf("     $$          ");
	}
	else {
		printf("     $$$  $     \n");
		printf("          $$    ");
	}
}

void drawCharacter2(int characterY, bool leg) {
	gotoxy(0, characterY);

	for (int i = 0; i < 12; i++) {
		printf("%s", C2[i]);
	}

	if (leg) {
		printf("    !____!,  |_ !   \n");
		printf("          !____!    ");
	}
	else {
		printf("     _|  ,!____!   \n");
		printf("    !____!          ");
	}

	//printf("     _|  ,,  |_ !  \n");
	//printf("    !____!!____!    ");

}

void drawGround(int groundY) {
	gotoxy(0, groundY);

	for (int i = 0; i < CONSOLE_X; i++) {
		printf("=");
	}
	printf("\n");
	for (int i = 0; i < CONSOLE_X; i++) {
		printf("=");
	}
}

void drawObstacle(int obstacleX, int obstacleY, char* word) {
	gotoxy(obstacleX, obstacleY);
	printf("   |||    \n");
	gotoxy(obstacleX, obstacleY + 1);
	printf("   |||   \n");
	gotoxy(obstacleX, obstacleY + 2);
	printf("  |||||  \n");
	gotoxy(obstacleX + 5 - ((int) strlen(word)/2), obstacleY + 3);
	printf("%s\n", word);
	gotoxy(obstacleX, obstacleY + 4);
	printf("  |||||  \n");
	gotoxy(obstacleX, obstacleY + 5);
	printf(" ||||||| \n");
	gotoxy(obstacleX, obstacleY + 6);
	printf(" ||||||| \n");
}
void clearObstacle(int obstacleX, int obstacleY, char* word) {
	for (int i = 0; i < 7; i++) {
		if (i == 3) {
			gotoxy(obstacleX + 5 - ((int)strlen(word) / 2), obstacleY + i);
			printf("                          \n");
		}
		gotoxy(obstacleX, obstacleY + i);
		printf("          \n");
	}
}

void drawScore(int score) {
	gotoxy(120, 4);
	printf("점수 : %06d", score);
}

// 영단어는 띄어쓰기 포함됨 || 난이도 하 : 6자리 까지 (947행까지) || 난이도 중 : 7~9자리 (2075행까지) || 난이도 상 : (2940행까지)
void selectWord(int level, char* word) {	//enWords.txt에서 난이도별로 렌덤 단어 뽑아서 word[]에 저장
	srand((unsigned)time(NULL));
	int randomRow;
	if (level == 1) {
		randomRow = rand() % 947 + 1;
	}
	else if (level == 2) {
		randomRow = rand() % 1128 + 948;
	}
	else {
		randomRow = rand() % 865 + 2076;
	}

	FILE* fp = fopen("enWords.txt", "r");
	if (fp != NULL) {
		for (int i = 1; i <= randomRow; i++) {
			fgets(word, WORD_MAXLEN - 2, fp);
			word[strlen(word) - 1] = '\0';
		}
	}
	else {
		system("cls");
		printf("enWords.txt 파일이 없습니다.");
	}
	fclose(fp);
}

void typingGame(int level) { // 레벨 1 : 하  / 레벨 2 : 중 / 레벨 3 : 상
	int obstacleX = OBSTACLE_START_X;	
	bool leg = true;

	const int speed_level = 1;

	int crashNum = 0;				//장애물과 충돌했을 때 중가시킬 변수
	int* crashNumP = &crashNum;

	int score = 0;			//점수

	char inputWord[WORD_MAXLEN] = { 0, };	//사용자 입력받은 문자열 저장
	int idx = 0;							//사용자 입력받은 문자열 index
	
	char word[WORD_MAXLEN] = { 0, };
	selectWord(level, word);

	system("cls"); 
	drawHeart(crashNumP, level);
	drawScore(score);
	drawGround(GROUND_Y);	
	//단어 입력하는 곳 표시 || 단어 입력하는 곳 좌표 : gotoxy(65, 40);
	for (int i = 0; i < WORD_MAXLEN; i++) {
		gotoxy(65 + i, 41);
		printf("~");
	}
	while (1) {
		
		if (selectCharacterNum == 1) {
			drawCharacter1(CHARACTER_Y, leg);
			leg = !leg;
		}
		else {
			drawCharacter2(CHARACTER_Y, leg);
			leg = !leg;
		}

		// 장애물 반복해서 그려주기 (speed_level) 만큼 앞으로 가서.
		clearObstacle(obstacleX + speed_level, OBSTACLE_Y, word);
		drawObstacle(obstacleX, OBSTACLE_Y, word);
		obstacleX = obstacleX - speed_level;

		//캐릭터랑 충돌했을 때 처리 / 하트 감소, 새로운 단어 출력
		if (obstacleX <= CHARACTER_X) {	
			clearObstacle(CHARACTER_X + 1, OBSTACLE_Y, word);
			obstacleX = OBSTACLE_START_X;
			crashNum += 1;

			drawHeart(crashNumP, level);	//하트 감소
			selectWord(level, word);
		}


		//문자열 입력받아 inputWord[]에 저장
		if (_kbhit()) {		
			char ch = _getch();
			if (ch == 13) {				//엔터
				//일치하는지 판단 & 점수 증가
				if (!strcmp(word, inputWord)) {	// 같을 때  //strcmp : 같으면 0 반환
					score += 10 * level;
					drawScore(score);	//score 반영						
					selectWord(level, word);	//새 단어 선택   || 제일 긴 단어 테스트 /strcpy(word, "artificial neural network\0");
					//장애물 맨 뒤로 보내기
					clearObstacle(obstacleX + speed_level, OBSTACLE_Y, word);
					obstacleX = OBSTACLE_START_X;		
				}
				gotoxy(65, 40);
				printf("                             ");
				for (int i = 0; i < 30; i++) {
					inputWord[i] = '\0';
				}
				idx = 0;
			}
			else if (ch == 8) {		//백스페이스
				if (idx > 0) {
					idx -= 1;
					inputWord[idx] = '\0';
					gotoxy(65, 40);
					printf("%s ", inputWord);
				}
				else {
					gotoxy(65, 40);
					printf("%s ", inputWord);
					inputWord[idx] = '\0';
				}
			}
			else if ((97 <= ch && ch <= 122) || (65 <= ch && ch <= 90) || ch == 32 || ch == 45) {	//띄어쓰기, - 입력도 받기
				if (idx < WORD_MAXLEN - 1) {
					inputWord[idx] = ch;
					gotoxy(65, 40);
					printf("%s", inputWord);
					idx += 1;
				}
				else {
					inputWord[idx-1] = ch;
					gotoxy(65, 40);
					printf("%s", inputWord);
					idx = WORD_MAXLEN - 2;
				}
			}
		}

		Sleep(100);
	}




}