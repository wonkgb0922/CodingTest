#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int k, cnt = 0;
int res = 0;

// A[p..q]와 A[q + 1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// A[p..q]와 A[q + 1..r]은 이미 오름차순으로 정렬되어 있다.
// v[p, q], v[q + 1, r]
// v[0, 2] v[3, 4]

bool merge(vector<int>& v, int p, int q, int r) {
    int i = p;
    int j = q + 1;

    vector<int> temp;

    while (i <= q && j <= r) {
        if (v[i] <= v[j])
        {
            //tmp[t++] = v[i++]; // tmp[t] < -A[i]; t++; i++;
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            //tmp[t++] = v[j++]; // tmp[t] < -A[j]; t++; j++;
            temp.push_back(v[j]);
            j++;
        }
    }
    while (i <= q)  // 왼쪽 배열 부분이 남은 경우
    {
        //tmp[t++] = v[i++];
        temp.push_back(v[i]);
        i++;
    }
    while (j <= r)  // 오른쪽 배열 부분이 남은 경우
    {
        //tmp[t++] = v[j++];
        temp.push_back(v[j]);
        j++;
    }
    i = 0;
    /*for (;i < temp.size(); i++)
    {
        printf("temp[%d] : %d || v[%d] : %d\n", i, temp[i], i, v[i]);
 
    }*/
    i = p;
    int t = 0;
    while (i <= r)  // 결과를 A[p..r]에 저장
    {
        v[i++] = temp[t++];
        cnt++;
        if (cnt == k)
        {
            res = v[i-1];
            return true;
        }
    }
    return false;
    
}

void merge_sort(vector<int>& v, int p, int r) {
    // A[p..r]을 오름차순 정렬한다.
    if (p < r)
    {
        int q = (p + r) / 2;       // q는 p, r의 중간 지점
        merge_sort(v, p, q);      // 전반부 정렬
        merge_sort(v, q + 1, r);  // 후반부 정렬
        // 병합
        if(merge(v, p, q, r)) return;
        else if (cnt < k)
        {
            res = -1;
            return;
        }
    }
}


int main(void){
    int n, input;
    vector<int> v;
	
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> input;

        v.push_back(input);
    }
    merge_sort(v, 0, v.size()-1);

    printf("%d", res);
	return 0;
    
}