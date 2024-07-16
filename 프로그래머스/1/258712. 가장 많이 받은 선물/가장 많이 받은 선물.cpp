#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, multiset<string>> m;
    multiset<string> s1, s2; // 준 것 받은 것 카운트 위함
    int val[50];
    vector<int> v(50);
    string a, b;
    
    for(int i = 0; i < gifts.size(); i++) {
        // 문자열 분할
        for(int j = 0; j < gifts[i].length(); j++) {
            if(gifts[i][j] == ' ') {
                a = gifts[i].substr(0, j);
                b = gifts[i].substr(j + 1);
            }
        }
        auto t = m.find(a);
        if(t == m.end()) {
            t = m.insert({a, multiset<string>()}).first;
        }
        t->second.insert(b);
        s1.insert(a);
        s2.insert(b);
    }
    for(int i = 0; i < friends.size(); i++) {
        val[i] = s1.count(friends[i]) - s2.count(friends[i]);
    }
    for(int i = 0; i < friends.size(); i++) {
        auto t = m.find(friends[i]);
        for(int j = i + 1; j < friends.size(); j++) {
            auto t2 = m.find(friends[j]);
            int l = 0, r = 0;
            if(t != m.end()) l = t->second.count(friends[j]);
            if(t2 != m.end()) r = t2->second.count(friends[i]);
            if(l > r)
                v[i]++;
            else if(l < r)
                v[j]++;
            else {
                if(val[i] < val[j])
                    v[j]++;
                else if(val[i] > val[j])
                    v[i]++;
            }
        }
    }
    answer = *max_element(v.begin(), v.end());
    return answer;
}