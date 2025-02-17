#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0, day;
    bool isPass;
    for(int i = 0; i < schedules.size(); i++) {
        schedules[i] += 10;
        if(schedules[i] % 100 >= 60) {
            schedules[i] -= 60;
            schedules[i] += 100;
        }
        day = startday;
        isPass = true;
        for(auto& it : timelogs[i]) {
            if(day % 7 != 0 && day % 7 != 6) {
                if(schedules[i] < it) {
                    isPass = false;
                    break;
                }
            }
            day++;            
        }
        if(isPass) answer++;
    }
    return answer;
}