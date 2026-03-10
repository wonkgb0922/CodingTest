#include <iostream>

using namespace std;

int main(void)
{
	int a, b, v;
	int distance; // 낮~밤 하루에 움직이는 거리
	int day;
	int cnt = 1;

	cin >> a >> b >> v;
	if (a < v)
	{
		v -= a;
		distance = a - b;
		day = v/distance;
		if (v % distance > 0) day++;
		cnt += day;
		//cout << "day : " << day << "\ndistance : " << distance << endl;
	}

	cout << cnt << endl;

	return 0;
	
}