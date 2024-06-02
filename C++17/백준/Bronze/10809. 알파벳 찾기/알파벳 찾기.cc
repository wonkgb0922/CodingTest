#include <stdio.h>
#include <string.h>

int main()
{
	char s[100];
	int ary[26];
	int i;
	scanf("%s", &s);
	for (i = 0; i < 26; i++)
		ary[i] = -1;

	for (i = 0; i < strlen(s); i++)
	{
		if (ary[s[i] - 'a'] == -1) ary[s[i] - 'a'] = i;
	}
	for (i = 0; i < 26; i++)
		printf("%d ", ary[i]);

	return 0;
}