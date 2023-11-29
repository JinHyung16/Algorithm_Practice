#include<iostream>
#include<vector>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Gold5 탑 - 자료구조 알고리즘
/// 2중 반복문을 돌면 시간초과가 난다.
/// 따라서 입력을 받아 stack값과 비교하여 바로바로 지우면서 비교한다.
/// 왜냐면 이미 지나간 탑은 볼 필요가 없기 때문이다.
/// </summary>

int main(void)
{
	FastIO;

	int N = 0; // 탑의 수 N
	cin >> N;

	stack<pair<int,int>> stk;
	stack<int> result;

	int input = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> input;

		while (!stk.empty())
		{
			if (input < stk.top().first)
			{
				cout << stk.top().second << " ";
				break;
			}
			stk.pop();
		}
		if (stk.empty())
		{
			cout << 0 << " ";
		}
		stk.push(make_pair(input, i + 1));
	}

	return 0;
}