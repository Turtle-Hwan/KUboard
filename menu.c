#include <stdio.h>

int main() {
	int num = 0, num2 = 0;
	char ch = 0;
	while (1) {
		printf("**********************************\n");
		printf("*         Ÿ�� ���� ����         *\n");
		printf("**********************************\n");
		printf("          1. ���� ����\n");
		printf("          2. ��ŷ Ȯ��\n");
		printf("          3. ���� ����\n");
		scanf("%d", &num);

		if (num == 1) {
			printf("���̵��� �����ϼ���!\n");
			printf("1. ��\n");
			printf("2. ��\n");
			printf("3. ��\n");
			scanf("%d", &num2);
			if (num == 1)
				printf("���̵� �� ���� ����!\n");
			else if (num == 2)
				printf("���̵� �� ���� ����!\n");
			else if (num == 3)
				printf("���̵� �� ���� ����!\n");
		}
		else if (num == 2) {
			printf("��ŷ Ȯ��\n");
		}
		else if (num == 3)
			break;
	}
	return 0;
}