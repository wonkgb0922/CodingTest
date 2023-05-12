#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <memory.h>

using namespace std;

int n;
string ary[100];
bool visited[101][101] = {false};
int res1 = 0, res2 = 0;
queue<pair<int, int>> q;

void dfs(const int i, const int j)
{
	//cout << "dfs : : " << i << " " << j << ", n : " << n << endl;
	//bool d = false;
	pair<int, int> res;
	visited[i][j] = true;
	if (i + 1 < n)	// 아래 방향
	{
		//cout << "if 내부 : " << i + 1 << " < " << n << endl;
		if ((ary[i][j] == ary[i + 1][j]) && !visited[i + 1][j])
		{
			//cout << "if문 내부2 : " << ary[i][j] << " == " << ary[i + 1][j] << " bool : " << (ary[i][j] == ary[i + 1][j]) << endl;
			//visited[i + 1][j] = true;z`
			//d = true;
			//res = dfs(i + 1, j);
			dfs(i + 1, j);
		}
		else
		{
			if (!visited[i + 1][j])
			{
				//cout << "아래방향" << i << " " << j << endl;
				q.push(make_pair(i + 1, j));
			}
		}
	}
	if (i - 1 >= 0)	// 윗 방향
	{
		if (ary[i][j] == ary[i - 1][j] && !visited[i - 1][j])
		{
			//visited[i - 1][j] = true;
			//d = true;
			//res = dfs(i - 1, j);
			dfs(i - 1, j);
		}
		else
		{
			if (!visited[i - 1][j])
			{
				q.push(make_pair(i - 1, j));
			}
		}
	}
	if (j + 1 < n)	// 오른 방향
	{
		if (ary[i][j] == ary[i][j + 1] && !visited[i][j + 1])
		{
			//visited[i][j + 1] = true;
			//d = true;
			//res = dfs(i, j + 1);
			dfs(i, j + 1);
		}
		else
		{
			if (!visited[i][j + 1])
			{
				q.push(make_pair(i, j + 1));
			}
		}
	}
	if (j - 1 >= 0)	// 왼 방향
	{
		if (ary[i][j] == ary[i][j - 1] && !visited[i][j - 1])
		{
			//visited[i][j - 1] = true;
			//d = true;
			//res = dfs(i, j - 1);
			dfs(i, j - 1);
		}
		else
		{
			if (!visited[i][j - 1])
			{
				q.push(make_pair(i, j - 1));
			}
		}
	}
	//if (!d) res = make_pair(i, j);
	//return res;
}
void dfs2(const int i, const int j)	// 색약 dfs
{
	//cout << "dfs : : " << i << " " << j << ", n : " << n << endl;
	bool d = false;
	//pair<int, int> res;
	visited[i][j] = true;
	if (i + 1 < n)	// 아래 방향
	{
		//cout << ary[i][j] << " " << ary[i+1][j] << " res : " << (ary[i][j] == 'R' && ary[i + 1][j] == 'G') << " visited : " << visited[i+1][j] <<  endl;
		//cout << "if 내부 : " << i + 1 << " < " << n << endl;
		if (((ary[i][j] == ary[i + 1][j]) ||(ary[i][j] == 'G' && ary[i + 1][j] == 'R') ||(ary[i][j] == 'R' && ary[i + 1][j] == 'G')) && (!visited[i + 1][j]))
		{
			//cout << "if문 내부2 : " << ary[i][j] << " == " << ary[i + 1][j] << " bool : " << (ary[i][j] == ary[i + 1][j]) << endl;
			//visited[i + 1][j] = true;
			d = true;
			//res = dfs(i + 1, j);
			dfs2(i + 1, j);
		}
		else
		{
			if (!visited[i + 1][j])
			{
				//cout << "아래방향" << i << " " << j << endl;
				q.push(make_pair(i + 1, j));
			}
		}
	}
	if (i - 1 >= 0)	// 윗 방향
	{
		if ((ary[i][j] == ary[i - 1][j] ||
			(ary[i][j] == 'G' && ary[i - 1][j] == 'R') ||
			(ary[i][j] == 'R' && ary[i - 1][j] == 'G')) && !visited[i - 1][j])
		{
			//visited[i - 1][j] = true;
			d = true;
			//res = dfs(i - 1, j);
			dfs2(i - 1, j);
		}
		else
		{
			if (!visited[i - 1][j])
			{
				q.push(make_pair(i - 1, j));
			}
		}
	}
	if (j + 1 < n)	// 오른 방향
	{
		if ((ary[i][j] == ary[i][j + 1] ||
			(ary[i][j] == 'G' && ary[i][j + 1] == 'R') ||
			(ary[i][j] == 'R' && ary[i][j + 1] == 'G')) && !visited[i][j + 1])
		{
			//visited[i][j + 1] = true;
			d = true;
			//res = dfs(i, j + 1);
			dfs2(i, j + 1);
		}
		else
		{
			if (!visited[i][j + 1])
			{
				q.push(make_pair(i, j + 1));
			}
		}
	}
	if (j - 1 >= 0)	// 왼 방향
	{
		if ((ary[i][j] == ary[i][j - 1] ||
			(ary[i][j] == 'G' && ary[i][j - 1] == 'R') ||
			(ary[i][j] == 'R' && ary[i][j - 1] == 'G')) && !visited[i][j - 1])
		{
			//visited[i][j - 1] = true;
			d = true;
			//res = dfs(i, j - 1);
			dfs2(i, j - 1);
		}
		else
		{
			if (!visited[i][j - 1])
			{
				q.push(make_pair(i, j - 1));
			}
		}
	}
	//if (!d) res = make_pair(i, j);
	//return res;
}

void bfs(int i, int j)
{
	q.push(make_pair(i, j));
	while (!q.empty())
	{
		pair<int, int> stt = q.front();
		q.pop();
		//cout << "q의 front() : " << stt.first << " " << stt.second << endl;
		if (visited[stt.first][stt.second]) continue;
		//pair<int,int> end = dfs(stt.first, stt.second);
		dfs(stt.first, stt.second);
		res1++;
		//cout << end.first << " " << end.second << endl;
	}
	memset(visited, false, sizeof(visited));
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		pair<int, int> stt = q.front();
		q.pop();
		if (visited[stt.first][stt.second]) continue;
		dfs2(stt.first, stt.second);
		res2++;
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
	}
	//visited[0][0] = true;
	bfs(0, 0);
	printf("%d %d", res1, res2);
	return 0;
}