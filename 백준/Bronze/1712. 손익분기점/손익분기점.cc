#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a, b, c;
    //unsigned long n;
    unsigned long tot;
    
    cin >> a >> b >> c;
    //scanf("%d%d%d", &a, &b, &c);
    
    if(b >= c) cout << -1;//n = -1;
    else
    {
        //n = a/(c-b)+1;
        cout << a/(c-b)+1;
    }
    //cout << n;
    
    return 0;
}
