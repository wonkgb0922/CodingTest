#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main(void){
    int n;
    int min = -1;
    int p = 665, cnt = 1;
    vector<int> v;
    bool d = false;

    cin >> n;

    while (n > 0)
    {
        d = false;
        v.clear();
        p += cnt;
        cnt = 1;
        int temp = p;
        
        while (temp > 0)
        {
            v.push_back(temp % 10);
            temp /= 10;
            }
        for (int i = 0; i < v.size() - 2; i++)
        {
            if (v[i] == 6 && (v[i] == v[i + 1] && v[i] == v[i + 2])) // 666연속
            {
                //printf("연속 666인 수와 n: %d, %d\n", p, n);
                d = true;
                if (i > 0)
                {
                    int ten = pow(10, i); //
                    if (n <= ten)
                    {
                        cnt = n - 1;
                        n = 0;
                        // 어차피 나감
                        p += cnt;
                    }
                    else
                    {
                        cnt = ten;
                        n -= ten;
                    }                   
                    //printf("10제곱 계산 후의 n : %d\n", n);
                    break;
                }
                else // i == 0
                {
                    cnt = 1;
                    n--;
                   /* if (v.size() > 3)
                    {
                        if (v[3] != 6)
                        {
                            cnt = 1000;
                        }
                    }*/
                   // printf("일반 계산 후의 n : %d\n", n);
                    break;
                }

            }
        }

    }
    printf("%d", p);
	return 0;
    
}