#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver4 바닥 장식 - Graph 이론 1388번
/// DFS는 한 방향으로 차례대로 모든 노드를 탐색하는 것
/// 이 아이디어를 기반으로 우측으로 먼저 다 돌고, 그 다음 아래로 내려가고를 반복 모든 i,j배열에 대해서
/// </summary>


int main(void)
{
	//입 출력 속도 up
	ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	//n은 세로, m은 가로
	int n(0), m(0);
	std::cin >> n >> m;

	vector<vector<char>> woods(n,vector<char>(m));
	int count = 0;

	//2차원 배열에서 세로는 열, 가로는 행의 해당
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> woods[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (woods[i][j] == '-')
			{
				//'-'우측으로 가다가 같은 행에 '|'가 나오면 그때서야 count 증가
				//왜냐면 '-'은 같은 행에 대해선 1개로 취급하기 때문
				if (j == m - 1 || woods[i][j + 1] == '|')
				{
					count++;
				}
			}
			if (woods[i][j] == '|')
			{
				// '|' 아래로 내려가다가 같은 열에 '-'가 나오면 그때서야 count 증가
				// 왜냐면 '|'는 같은 열에 대해선 1개로 취급하기 때문
				if (i == n - 1 || woods[i + 1][j] == '-')
				{
					count++;
				}
			}
		}
	}

	std::cout << count;
	return 0;
}