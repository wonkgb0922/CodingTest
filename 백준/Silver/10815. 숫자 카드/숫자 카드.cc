# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main(void)
{
    vector<int> v1;
    vector<int> v2;
    int a, input, i;
    cin >> a;
    for(i=0; i<a; i++)
    {
        cin >> input;
        v1.push_back(input);
    }
    sort(v1.begin(), v1.end());

    cin >> a;
    for(i=0;i<a;i++)
    {
        cin >> input;
        v2.push_back(input);
    }

    // 벡터에서 특정값을 찾기
    i=0;
    for(int &x : v2)
    {
        cout << binary_search(v1.begin(), v1.end(), v2[i]) << ' ';
        i++;
    }

    return 0;
}
