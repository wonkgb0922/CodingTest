#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
void hanoi(int n, int i, int j)
{
    int temp = 6 - (i + j);

    if (n <= 1)
    {
        printf("%d %d\n", i, j);
        return;
    }
    
    
    hanoi(n - 1, i, temp);
    printf("%d %d\n", i, j);
    hanoi(n - 1, temp, j);
}

int main(void){
    int n, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        res = res + res + 1;
    }
    printf("%d\n", res);
    hanoi(n, 1, 3);

	return 0;
    
}