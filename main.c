#include "header.h"

void consoleInfo() {	// 콘솔 창 제목과 크기 정하기
	system("title 타자 연습 게임_(C프로그래밍) 4조 김지환, 고영빈, 나예담, 김현지");
	system("mode con: cols=150 lines=50");
}

int main() {
	consoleInfo();
	mainMenu();

	return 0;
}