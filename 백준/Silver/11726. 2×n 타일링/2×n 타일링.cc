// 11726 : 2*n 탈일링
// D[n] = 2*n 직사각형을 만들 수 있는 타일의 방법의 수
//
# include <iostream>

using namespace std;

int d[1001];

int main(void)
{
    d[0] = 1;
    d[1] = 1;
    int n;
    cin >> n;

    for(int i=2;i<=n;i++)
    {
        d[i] = d[i-2] + d[i-1];
        d[i] %= 10007;
    }
    cout << d[n]<< endl;
    return 0;
}
