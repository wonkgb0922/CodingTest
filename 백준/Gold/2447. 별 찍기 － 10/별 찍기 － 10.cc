#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int ary[2187][2187] = { 0 };
void star(int n, int i, int j)
{
    if (n == 1)
    {
        ary[i][j] = 1;

    }
    else
    {
        star(n / 3, i, j);
        star(n / 3, i, j + (n/3));
        star(n / 3, i, j + (n/3)*2);

        star(n / 3, i + (n / 3), j);
        star(n / 3, i + (n / 3), j + (n / 3)*2);

        star(n / 3, i + (n / 3)*2, j);
        star(n / 3, i + (n / 3)*2, j + (n / 3));
        star(n / 3, i + (n / 3)*2, j + (n / 3) * 2);
    }
}

int main(void){
    int n;
    cin >> n;
    star(n, 0, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ary[i][j] == 1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }

	return 0;
    
}