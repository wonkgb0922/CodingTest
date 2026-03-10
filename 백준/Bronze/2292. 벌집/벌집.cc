#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    int i, j = 1;
    cin >> n;
    if(n == 1) cout << 1;
    else
    {
        for(i=1;n > j;i++)
        {
            j += 6*i;
        }
        cout << i;
    }
    return 0;
}
