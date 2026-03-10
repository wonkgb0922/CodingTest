// 10867 : 중복빼고 정렬하기
# include <iostream>
# include <set>

using namespace std;

int main(void)
{
    int n, input, i;
    set<int> s1;
    cin >> n;
    while(n--)
    {
        cin >> input;
        s1.insert(input);
    }
    for(int x : s1)
        cout << x << ' ';

    return 0;
}
