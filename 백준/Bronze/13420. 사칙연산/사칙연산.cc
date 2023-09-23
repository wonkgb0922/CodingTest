#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
	int n;
	long long in1, in2, in3, res;
	char ope, eq;
	cin >> n;
	while (n--) {
		scanf("%lld %c %lld %c %lld", &in1, &ope, &in2, &eq, &in3);
		if (ope == '+')
			res = in1 + in2;
		else if (ope == '-')
			res = in1 - in2;
		else if (ope == '*')
			res = in1 * in2;
		else
			res = in1 / in2;
		if (res == in3) printf("correct\n");
		else printf("wrong answer\n");
	}
}