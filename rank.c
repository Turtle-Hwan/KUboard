#include "header.h"

#define MAX 30

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

void sorting(const char* text) {
	FILE* fp = fopen(text, "a");
	fseek(fp, 0, SEEK_END);
	int rank_length = ftell(fp);
	char* nam = (char*)malloc(sizeof(char) * rank_length);
	int* num = (int*)malloc(sizeof(int) * rank_length);
	for (int i = 0; i < rank_length; i++) {
		fgets(nam,3,fp);
		fgets(num, 6, fp);
	}

	fclose(fp);
}

void saveRanking(const char* name, const int score) { // 저장 양식 KIM 000150
	FILE* fp = fopen("ranking.txt", "a");
	fprintf(fp, "%3c %06d", name[0], score);
	fputs("\n", fp);


	// 순위에 맞추어 정렬하는 부분 추가
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
