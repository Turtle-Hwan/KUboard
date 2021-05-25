#include<stdio.h>
#include<Windows.h>
#include<string.h>

#define REVEL1 15

void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}  // 콘솔창 이동 // 콘솔창 이동

void Time()
{
	int count;
	if (REVEL1 < 10)
	{
		gotoxy(1, 0);
		printf("%d", REVEL1);
	}
	else
	{
		gotoxy(0, 0);
		printf("%d", REVEL1);
	}
	
	Sleep(1000);
	for (count = REVEL1 - 1; count > 0; count--)
	{
		gotoxy(0, 0);
		printf(" ");
		gotoxy(1, 0);
		printf(" ");
		if (count < 10)
		{
			gotoxy(1, 0);
			printf("%d", count);
			Sleep(1000);
		}
		else
		{
			gotoxy(0, 0);
			printf("%d", count);
			Sleep(1000);
		}
	}
}  // 시간 타이머  // 시간 타이머

void Heart(char str[30])
{
	char a[20];
	int b, i = 0; // i = 틀린 횟수
	gotoxy(10, 0);
	printf("♥ ♥ ♥ ♥ ♥");
One:
	gotoxy(3, 5);
	printf("입력 : ");
	gotoxy(10, 5);
	printf("     ");
	gotoxy(10, 5);
	scanf("%s", &a);
	b = strcmp(a, str);
	if (b)
	{
		i++;
		do
		{
			if (i == 1)
			{
				gotoxy(10, 0);
				printf("♡ ♥ ♥ ♥ ♥");
			}
			else if (i == 2)
			{
				gotoxy(10, 0);
				printf("♡ ♡ ♥ ♥ ♥");
			}
			else if (i == 3)
			{
				gotoxy(10, 0);
				printf("♡ ♡ ♡ ♥ ♥");
			}
			else if (i == 4)
			{
				gotoxy(10, 0);
				printf("♡ ♡ ♡ ♡ ♥");
			}
			else
			{
				gotoxy(10, 0);
				printf("♡ ♡ ♡ ♡ ♡");
			}
			goto One;
		} while (i < 6);
	}
	else
		goto One;
}   // 생명력   // Heart("문자열") -> 문자열이랑 다를 시 하트 깍임

int main()
{
	Heart("hello");
}
