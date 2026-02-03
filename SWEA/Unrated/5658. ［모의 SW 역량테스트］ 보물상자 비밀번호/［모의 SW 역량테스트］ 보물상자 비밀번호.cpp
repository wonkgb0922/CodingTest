#include<iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <functional>

using namespace std;

vector<string> v;
set<unsigned long long int, greater<unsigned long long int>> s;

unsigned long long int hexToDecimal(int idx)
{
    string hex = v[idx];
    std::stringstream ss;
    ss  << std::hex << hex;
    long long int ret;
    ss >> ret;
    return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, n, k, res;
	string str;
	cin >> T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n >> k;
        cin >> str;
        s = set<unsigned long long int, greater<unsigned long long int>>();
        res = 0;
        str += str;
        for(int q = 0; q < n; q++) {
            v.clear();
            // 1. split
            for(int i = 0; i < 4; i++) {
                v.push_back(str.substr(q + (i * (n / 4)), n / 4));
            }
            
            for(int i = 0; i < 4; i++) {
                unsigned long long int val = hexToDecimal(i);
                s.insert(val);
            }
        }
        set<unsigned long long int>::iterator it = s.begin();
        k--;
        while(k--) it++;
        

        cout << "#" << test_case << " " << *it << '\n';
	}
	return 0;
}
