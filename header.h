#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

//consoleInfo의 가로, 세로 길이
#define CONSOLE_X 150
#define CONSOLE_Y 50

//영단어 최대 길이
#define WORD_MAXLEN 30


void gotoxy(int x, int y);				//timeHeart.c에 정의, 온갖 곳에서 사용
void color(char text[], int i);			//콘솔 색깔

void mainMenu();						//menu.c에 정의, main() 에서 사용


void itemExplainMenu(); // menu.c에서 사용
void ITEM();


void checkRanking(char ranking[][12]);	//rank.c에 정의, menu.c -> rankingMenu() 에서 사용
void saveRanking(const char* name, const int score);
//typedef struct {		//ranking 저장에 필요한 구조체
//	int score;
//	char name[4];
//}user;


void typingGame(int *level);			//typingGame.c에 정의, menu -> selectLevelMenu() 에서 사용
void drawHeart(int* i, int level);		//timeHeart.c 정의 , typingGame()에 사용


void pauseMenu(int*);					//menu.c에 정의, typingGame()에 사용
void gameOverMenu();

// 영단어는 띄어쓰기 포함됨 || 난이도 하 : 6자리 까지 (947행까지) || 난이도 중 : 7~9자리 (2075행까지) || 난이도 상 : (2940행까지)

