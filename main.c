#include "header.h"

void consoleInfo() {	// �ܼ� â ����� ũ�� ���ϱ�
	system("title Ÿ�� ���� ����_(C���α׷���) 4�� ����ȯ, ����, ������, ������");
	system("mode con: cols=150 lines=50");
}

int main() {
	consoleInfo();
	mainMenu();

	return 0;
}