#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0, cnt;
    bool isAns;
    set<int> s;
    for(int a = 1; a < n; a++) {
        s.insert(a);
        for(int b = a + 1; b < n; b++) {
            s.insert(b);
            for(int c = b + 1; c < n; c++) {
                s.insert(c);
                for(int d = c + 1; d < n; d++) {
                    s.insert(d);
                    for(int e = d + 1; e <= n; e++) {
                        s.insert(e);
                        
                        // 일단 만듬
                        
                        isAns = true;
                        for(int i = 0; i < q.size(); i++) {
                            cnt = 0;
                            for(auto& it : q[i]) {
                                if(s.find(it) != s.end()) cnt++;
                            }
                            if(cnt != ans[i]) {
                                isAns = false;
                                break;
                            }
                        }
                        if(isAns) answer++;
                        s.erase(e);
                    }
                    s.erase(d);
                }
                s.erase(c);
            }
            s.erase(b);
         }
        s.erase(a);
    }
    return answer;
}