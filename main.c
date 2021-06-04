#include "header.h"

void consoleInfo() {	// 콘솔 창 제목과 크기 정하기
	system("title 타자 연습 게임_(C프로그래밍) 4조 김지환, 고영빈, 나예담, 김현지");
	system("mode con: cols=150 lines=50");
}

int main() {
	// SetConsoleOutputCP(949); // 혹시 콘솔 한글 글씨가 깨진다면 실행할 구문

	PlaySound(TEXT("bgm.wav"), NULL, SND_ASYNC | SND_LOOP | SND_SYSTEM);
	consoleInfo();
	mainMenu();

	return 0;
}