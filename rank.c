#include "header.h"

#define MAX 30

bool correct(const char* que) {

	char arr[MAX];
	gets_s(arr, MAX);
	int a = strcmp(que, arr);
	if (a == 0) {
		return 1; // �ι��ڰ� ��ġ�� ��
	}
	else {
		return 0;
	}
}

void saveRanking(const char* name, const int score) { // ���� ��� KIM 000150
	FILE* fp = fopen("ranking.txt", "a");
	fputs(name, fp);
	fprintf(fp, " %06d", score);
	fputs("\n", fp);


	// ������ ���߾� �����ϴ� �κ� �߰�
	fclose(fp);
}

void checkRanking(char ranking[][11]) { //��ŷ ����� �迭 (10������ ����)
	FILE* fp;
	fp = fopen("ranking.txt", "a+");
	
	for (int i = 0; i < 10; i++) {
		if (fgets(ranking[i], sizeof(ranking), fp) == NULL) {
			break;
		}
	}
	fclose(fp);
}