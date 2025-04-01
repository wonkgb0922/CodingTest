#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int input, i, cnt = 0;
	int arr[42] = { 0 };
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &input);
		arr[input % 42]++;
	}
	for (i = 0; i < 42; i++)
	{
		if (arr[i] > 0)
		{
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}