#include <stdio.h>

void findWord() {
	FILE* fp, * fpw;

	fopen_s(&fp, "2022수특 영단어장(영어).txt", "r");
	fopen_s(&fpw, "enword.txt", "w");


	char line[255];
	while (fgets(line, sizeof(line), fp) != NULL) {
		int i = 0;
		while (!(line[i] >= 'a' && line[i] <= 'z')) {
			if (line[i] == '\0')
				break;
			i++;
		}
		printf("%s", line);

	}

	fclose(fp);
	fclose(fpw);

	return 0;
}
