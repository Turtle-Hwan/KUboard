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
	fprintf(fp, "%3c %06d", name[0], score);
	fputs("\n", fp);


	// ������ ���߾� �����ϴ� �κ� �߰�
	fclose(fp);
}

void checkRanking(char ranking[][12]) { //��ŷ ����� �迭 (10������ ����)
	FILE* fp;
	fp = fopen("ranking.txt", "a+");
	
	for (int i = 0; i < 10; i++) {
		if (fgets(ranking[i], 11, fp) == NULL) {
			break;
		}
	}
	fclose(fp);
}