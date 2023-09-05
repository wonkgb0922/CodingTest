# include <stdlib.h>
# include <stdio.h>
# include <iostream>
# include <stack>

using namespace std;

int main(void)
{
	int n,input;

	scanf("%d", &n);

	stack<pair<int, int>> s;

	for (int i = 1; i <= n; i++)
	{
	    scanf("%d", &input);
		if(!s.empty())
		{
			if (s.top().first < input)
			{
				while (!s.empty() && s.top().first < input) s.pop();

				if (!s.empty())
					cout << s.top().second << " ";
				else cout << 0 << " ";
				s.push({ input,i });
			}
			else
			{
				cout << s.top().second << " ";
				s.push({ input, i });
			}

		}
		else
		{
			cout << 0 << " ";
			s.push({ input, i });
		}
	}

	return 0;
}