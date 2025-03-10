#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int w, int num) {
    int answer = 0;
    int layer = (num - 1) / w;
    int col;
    if(layer % 2) {
        col = w - (num % w);
        if(col == w) col = 0;
    }
    else 
        col = (num - 1) % w;
    
    while(true) {
        answer++;
        if(layer % 2) {
            num += col * 2 + 1;
        }
        else
            num += (w - col - 1) * 2 + 1;
        layer++;
        if(num > n) break;
    }
    return answer;
}