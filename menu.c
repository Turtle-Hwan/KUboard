#include <stdio.h>

int main() {
	int num = 0, num2 = 0;
	char ch = 0;
	while (1) {
		printf("**********************************\n");
		printf("*         타자 연습 게임         *\n");
		printf("**********************************\n");
		printf("          1. 게임 시작\n");
		printf("          2. 랭킹 확인\n");
		printf("          3. 게임 종료\n");
		scanf("%d", &num);

		if (num == 1) {
			printf("난이도를 선택하세요!\n");
			printf("1. 상\n");
			printf("2. 중\n");
			printf("3. 하\n");
			scanf("%d", &num2);
			if (num == 1)
				printf("난이도 상 게임 시작!\n");
			else if (num == 2)
				printf("난이도 중 게임 시작!\n");
			else if (num == 3)
				printf("난이도 하 게임 시작!\n");
		}
		else if (num == 2) {
			printf("랭킹 확인\n");
		}
		else if (num == 3)
			break;
	}
	return 0;
}