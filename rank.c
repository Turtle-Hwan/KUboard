#include "header.h"

#define MAX 30

typedef struct {
	int score;
	char name[3];
}user;

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

void sorting(const char* text, int count) {
	FILE* fp = fopen(text, "a");
	fseek(fp, 0, SEEK_END);
	int rank_length = ftell(fp);
	char* wt = (char*)malloc(sizeof(char) * rank_length);
	user* u = (user*)malloc(sizeof(user) * count);
	while (!feof(fp)) {
		int i = 0;
		fgets(wt, 10, fp); // 부분 미완성
	}
	fclose(fp);
}

void saveRanking(const char* name, const int score) { // 저장 양식 KIM 000150
	FILE* fp = fopen("ranking.txt", "a");
	fprintf(fp, "%3s %6d", name, score);
	fputs("\n", fp);
	fclose(fp);
	int count = getTotalLine("ranking.txt");
	printf("%d", count);
	sorting("ranking.txt", count);
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
