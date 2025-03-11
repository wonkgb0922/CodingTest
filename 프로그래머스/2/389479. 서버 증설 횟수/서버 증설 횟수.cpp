#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0, cnt;
    for(int i = 0; i < players.size(); i++) {
        if(players[i] >= m) {
            cnt = players[i] / m;
            answer += cnt;
            for(int j = 0; j < k && i + j < 24; j++) {
                players[i + j] -= m * cnt;
            }
        }
    }
    return answer;
}