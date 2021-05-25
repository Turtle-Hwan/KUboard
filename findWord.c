#include <stdio.h>

void findWord() {	//영어만 남기기
	FILE* fp, * fpw;

	fopen_s(&fp, "2022수특 영단어장(영어).txt", "r");
	fopen_s(&fpw, "enword.txt", "w");


	char line[255];
	while (fgets(line, sizeof(line), fp) != NULL) {
		if (line[0] >= 'a' && line[0] <= 'z') {
			printf("%s", line);
			fputs(line, fpw);
		}
	}

	fclose(fp);
	fclose(fpw);

	return 0;
}

void sortWords() {
	FILE* fp, * fpw;

	fopen_s(&fp, "2022수특 영단어장(영어).txt", "r");
	fopen_s(&fpw, "enword.txt", "w");


	char line[3000][40];
	int idx = 0;
	//파일 읽기
	while (fgets(line[idx], sizeof(line[idx]), fp) != NULL) {
		idx++;
	}

	//quickSort(line, 0, idx);

	char tmp[40];
	for (int i = idx - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strlen(line[j]) > strlen(line[j + 1])) {
				strcpy(tmp, line[j]);
				strcpy(line[j], line[j + 1]);
				strcpy(line[j + 1], tmp);
			}
		}
	}


	for (int k = 0; k < idx; k++) {
		printf("%s", line[k]);
		//fputs(line[k], fpw);
	}


	fclose(fp);
	fclose(fpw);

	return 0;

}

//void quickSort(char* line[][40], int start, int idx) {
//	//퀵정렬
//	if (start >= idx - 1) {
//		return;
//	}
//	int pivot = start;
//	int i = pivot + 1;
//	int j = idx - 1;
//	char* temp[255];
//
//	while (i <= j) {
//		while (i <= idx - 1 && strlen(line[i]) <= strlen(line[pivot])) {
//			i++;
//		}
//		while (j > start && strlen(line[j]) >= strlen(line[pivot])) {
//			j--;
//		}
//		printf("%d\n", strlen(line[i]));
//
//		if (i >= j) break;
//
//
//			*temp[0] = line[i][0];
//			line[i][0] = line[j][0];
//			line[j][0] = *temp[0];	
//	}
//
//	temp[0] = line[j][0];
//	line[j][0] = line[pivot][0];
//	line[pivot][0] = temp[0];
//
//	printf("%d\n", pivot);
//	quickSort(line, start, j - 1);
//	quickSort(line, j + 1, idx);
//
//}