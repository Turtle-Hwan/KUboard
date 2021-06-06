#include "header.h"

#define MAX 30
#define MAX_RANK 5   //��ŷ ��� Ƚ�� ��ũ��


int getTotalLine(const char* name) {
	FILE* fp;
	int line = 0;
	char c;
	fp = fopen(name, "r");
	while ((c = fgetc(fp)) != EOF)
		if (c == '\n') 
			line++;
	fclose(fp);
	return line;
}

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

typedef struct {		//ranking ���忡 �ʿ��� ����ü
	int score;
	char name[4];
}user;

void sorting() {
	int count = getTotalLine("ranking.txt");
	FILE* fp = fopen("ranking.txt", "r+");

	int size = sizeof(user) * count;
	user *u = (user *)malloc(size);

	if (u != NULL) {

		memset(u, 0, size);	//0���� �ʱ�ȭ

		for (int i = 0; i < count; i++) {
			fscanf(fp, "%3s %6d", u[i].name, &u[i].score);
		}

		user temp;
		for (int i = 0; i < count - 1; i++) {
			for (int j = 1; j < count - i; j++) {
				if (u[j - 1].score < u[j].score) {
					//���ڿ� ����
					strcpy(temp.name, u[j - 1].name);
					strcpy(u[j - 1].name, u[j].name);
					strcpy(u[j].name, temp.name);

					//���ھ� ����
					temp.score = u[j - 1].score;
					u[j - 1].score = u[j].score;
					u[j].score = temp.score;
				}
			}
		}

		fclose(fp);

		FILE* fpw = fopen("ranking.txt", "w");
		fseek(fp, 0, SEEK_SET);
		for (int i = 0; i < count; i++) {
			fprintf(fp, "%3s %06d\n", u[i].name, u[i].score);
		}
		fclose(fpw);
		free(u);
	}
}

void saveRanking(const char* name, const int score) { // ���� ��� KIM 000150
	FILE* fp = fopen("ranking.txt", "a+");
	fprintf(fp, "%3s %06d\n", name, score);

	fclose(fp);
}

void checkRanking(char ranking[][12]) { //��ŷ ����� �迭 (10������ ����)
	FILE* fp;
	fp = fopen("ranking.txt", "a+");
	sorting();

	for (int i = 0; i < 10; i++) {
		if (fgets(ranking[i], 11, fp) == NULL) {
			break;
		}
		fgetc(fp);	//fgets�� \n�� ���� �����Ƿ� ���� ������ ���� ������ �Ű��ֱ�
	}
	fclose(fp);
}
