#include <string>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

bool visited[4][3];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    queue<pair<int,int>> q;
    bool isRight = (hand == "right");
    int l = 10, r = 12, qsize;
    bool findL, findR;

    for(auto& it : numbers) {
        if(it == 1 || it == 4 || it == 7) {
            answer += "L";
            l = it;
        }
        else if(it == 3 | it == 6|| it == 9) {
            answer += "R";
            r = it;
        }
        else { // 2 5 8 0일 때
            if(l == 10 && r == 12) {
                if(isRight) {
                    answer += "R";
                    r = it;
                }
                else {
                    answer += "L";
                    l = it;
                }
            }
            else {
                memset(visited, 0, sizeof(visited));
                q = queue<pair<int, int>>();
                findL = false, findR = false;
                int x = 1, y;
                if(it == 0) y = 3; 
                else y = it / 3;
                q.push({y, x});
                visited[y][x] = true;
                while(!q.empty()) {
                    qsize = q.size();
                    while(qsize--) {
                        auto t = q.front();
                        int tx = t.second;
                        int ty = t.first;
                        int loc = (ty * 3) + tx + 1;
                        if(loc == 11) loc = 0;
                        if(loc == l) findL = true;
                        if(loc == r) findR = true;
                        q.pop();
                        for(int i = 0; i < 4; i++) {
                            int ttx = tx + dir[i][0];
                            int tty = ty + dir[i][1];
                            if(ttx >= 0 && ttx < 3 && tty >= 0 && tty < 4) {
                                if(!visited[tty][ttx]){
                                    q.push({tty, ttx});
                                    visited[tty][ttx] = true;
                                }
                            }
                        }
                    }
                    if(findL && findR) {
                        if(isRight) {
                            answer += "R";
                            r = it;
                        }
                        else {
                            answer += "L";
                            l = it;
                        }
                        break;
                    }
                    else if(findL) {
                        answer += "L";
                        l = it;
                        break;
                    }
                    else if(findR) {
                        answer += "R";
                        r = it;
                        break;
                    }
                    
                }
            }
            
        }
    }
    return answer;
}