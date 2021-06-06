#include "header.h"

#define MAX 30
#define MAX_RANK 5   //랭킹 출력 횟수 매크로


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
		return 1; // 두문자가 일치할 때
	}
	else {
		return 0;
	}
}

typedef struct {		//ranking 저장에 필요한 구조체
	int score;
	char name[4];
}user;

void sorting() {
	int count = getTotalLine("ranking.txt");
	FILE* fp = fopen("ranking.txt", "r+");

	int size = sizeof(user) * count;
	user *u = (user *)malloc(size);

	if (u != NULL) {

		memset(u, 0, size);	//0으로 초기화

		for (int i = 0; i < count; i++) {
			fscanf(fp, "%3s %6d", u[i].name, &u[i].score);
		}

		user temp;
		for (int i = 0; i < count - 1; i++) {
			for (int j = 1; j < count - i; j++) {
				if (u[j - 1].score < u[j].score) {
					//문자열 정렬
					strcpy(temp.name, u[j - 1].name);
					strcpy(u[j - 1].name, u[j].name);
					strcpy(u[j].name, temp.name);

					//스코어 정렬
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

void saveRanking(const char* name, const int score) { // 저장 양식 KIM 000150
	FILE* fp = fopen("ranking.txt", "a+");
	fprintf(fp, "%3s %06d\n", name, score);

	fclose(fp);
}

void checkRanking(char ranking[][12]) { //랭킹 저장될 배열 (10위까지 저장)
	FILE* fp;
	fp = fopen("ranking.txt", "a+");
	sorting();

	for (int i = 0; i < 10; i++) {
		if (fgets(ranking[i], 11, fp) == NULL) {
			break;
		}
		fgetc(fp);	//fgets는 \n을 따로 읽으므로 파일 포인터 다음 행으로 옮겨주기
	}
	fclose(fp);
}
