#include "header.h"

#define MAX 30
#define MAX_RANK 5   //랭킹 출력 횟수 매크로


int getTotalLine(const char* name) {
	FILE* fp;
	int line = 0;
	char c;
	fp = fopen(name, "r");
	while ((c = fgetc(fp)) != EOF)
		if (c == '\n') line++;
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

void sorting() {
	int count = getTotalLine("ranking.txt");
	user* u = (user*)malloc(sizeof(user) * count);
	FILE* fp = fopen("ranking.txt", "rt");
	for (int i = 0; i < count; i++) {
		fscanf(fp, "%s %d", u[i].name, &u[i].score);
	}

	user temp;
	for (int i = 0; i < count - 1; i++) {
		for (int j = 1; j < count - i; j++) {
			if (u[j - 1].score < u[j].score) {
				for (int k = 0; k < 3; k++) {
					temp.name[k] = u[j - 1].name[k];
					u[j - 1].name[k] = u[j].name[k];
					u[j].name[k] = temp.name[k];
				}
				temp.score = u[j - 1].score;
				u[j - 1].score = u[j].score;
				u[j].score = temp.score;
			}
		}
	}
	for (int i = 0; i < MAX_RANK; i++) {
		printf("%d위 %s: %d점\n", i+1, u[i].name, u[i].score);
	}
	fclose(fp);
}

void saveRanking(const char* name, const int score) { // 저장 양식 KIM 000150
	FILE* fp = fopen("ranking.txt", "a");
	fprintf(fp, "%3s %6d", name, score);
	fputs("\n", fp);
	fclose(fp);
}

void checkRanking(char ranking[][12]) { //랭킹 저장될 배열 (10위까지 저장)
	FILE* fp;
	fp = fopen("ranking.txt", "a+");
	
	for (int i = 0; i < 10; i++) {
		if (fgets(ranking[i], 11, fp) == NULL) {
			break;
		}
	}
	fclose(fp);
}
