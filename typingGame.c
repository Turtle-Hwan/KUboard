#include "header.h"

#define GROUND_Y 33

#define OBSTACLE_Y 27

#define CHARACTER_Y 19
#define CHARACTER_X 17



void consoleInfo() {	// 콘솔 창 제목과 크기 정하기
	system("title 타자 연습 게임");
	system("mode con: cols=150 lines=50");
}

void consolePrint() {

}

void gotoXY(int x, int y) {		// 콘솔 창에 출력 위치
	COORD Cur;
	Cur.X = 2 * x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int selectCharacterNum;	//몇 번 캐릭터 선택했는지
char C1[17][25] = {
	"                \n",
	"         $$$$$$ \n",
	"       $$ $$$$$$\n",
	"       $$$$$$$$$\n",
	"$      $$$      \n",
	"$$      $$$$$$$ \n",
	"$$      $$$$$$$ \n",
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
	"    !----!!----!    \n"
};
void drawCharacter1(int characterY, bool leg) {




	gotoXY(0, characterY);

	printf("                \n");
	printf("         $$$$$$ \n");
	printf("       $$ $$$$$$\n");
	printf("       $$$$$$$$$\n");
	printf("$      $$$      \n");
	printf("$$      $$$$$$$ \n");
	printf("$$$   $$$$$$    \n");
	printf(" $$  $$$$$$$$$$$\n");
	printf(" $$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$    \n");
	printf("    $$$$$$$$    \n");
	printf("     $$$$$$     \n");
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
	gotoXY(0, characterY);

	printf("    :.   ..   .:    \n");
	printf("    | '- ;; -' |    \n");
	printf(" , -            - , \n");
	printf("   :   !_  _!   :   \n");
	printf("    :    --    :    \n");
	printf("   : -        - :   \n");
	printf("     -___  ___-     \n");
	printf("    ,-:* KU *:-,    \n");
	printf("   | :   ''   : |   \n");
	printf("   | :        : |  ,\n");
	printf("   (_ : -  - : _) ! \n");
	printf("      :  ,,  :   !  \n");
	if (leg) {
		printf("    !----!,  |_ !   \n");
		printf("          !----!    ");
	}
	else {
		printf("     _|  ,!----!   \n");
		printf("    !----!          ");
	}

	//printf("     _|  ,,  |_ !  \n");
	//printf("    !----!!----!    ");

}

void drawGround(int groundY) {
	gotoXY(0, groundY);

	printf("======================================================================================================================================================");
	printf("======================================================================================================================================================");
}

void drawObstacle(int obstacleX, int obstacleY) {
	gotoXY(obstacleX, obstacleY);
	printf("    |    \n");
	gotoXY(obstacleX, obstacleY + 1);
	printf("   |||   \n");
	gotoXY(obstacleX, obstacleY + 2);
	printf("  |||||  \n");
	gotoXY(obstacleX, obstacleY + 3);
	printf("  |||||  \n");
	gotoXY(obstacleX, obstacleY + 4);
	printf("  |||||  \n");
	gotoXY(obstacleX, obstacleY + 5);
	printf(" ||||||| \n");
	gotoXY(obstacleX, obstacleY + 6);
	printf("|||||||||\n");
}


void typeGame() {
	int obstacleX = 60;
	bool i = true;
	while (1) {

		drawCharacter1(CHARACTER_Y, i);

		i = !i;

		drawGround(GROUND_Y);

		drawObstacle(obstacleX, OBSTACLE_Y);
		obstacleX = obstacleX - 5;
		if (obstacleX <= 0) {
			obstacleX = 60;
		}

		if (obstacleX <= CHARACTER_X) {
			//충돌 처리
		}

		Sleep(1000);
		system("cls");
	}
}