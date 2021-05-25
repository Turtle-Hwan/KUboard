#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>

//#include <conio.h>
#define GROUND_Y 33
#define CHARACTER_Y 20
#define OBSTACLE_Y 27

#define CHARACTER_X 16


void console() {
	system("title 타자 연습 게임");
	system("mode con: cols=150 lines=50");
}

void consolePrint() {

}

void gotoXY(int x, int y) {
	COORD Cur;
	Cur.X = 2 * x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void drawCharacter(int characterY, bool leg) {
	gotoXY(0, characterY);

	printf("        $$$$$$$ \n");
	printf("       $$ $$$$$$\n");
	printf("       $$$$$$$$$\n");
	printf("$      $$$      \n");
	printf("$$     $$$$$$$  \n");
	printf("$$$   $$$$$     \n");
	printf(" $$  $$$$$$$$$$ \n");
	printf(" $$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$    \n");
	printf("    $$$$$$$$    \n");
	printf("     $$$$$$     \n");
	if (leg)
	{
		printf("     $    $$$    \n");
		printf("     $$          ");
		leg = true;
	}
	else
	{
		printf("     $$$  $     \n");
		printf("          $$    ");
		leg = false;
	}
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

		drawCharacter(CHARACTER_Y, i);
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

int main() {
	console();
	
	typeGame();
	

}