#include<iostream>
#include<vector>
#include<algorithm>

/// <summary>
/// Silver2 숫자판 점프 - Graph 알고리즘
/// DFS의 기본 재귀를 통한 필요
/// 중복된 숫자를 제거하는 과정이 필요하다
/// sort를 이용해 정렬한 뒤 unique를 통해 중복되지 않는 원소들을 채워간 뒤
/// erase를 통해 지워야 한다.
/// *아니면 set을 사용해 처음부터 중복을 방지할 수 있다.
/// </summary>

using namespace std;

const int N = 5; //맵 size N*N 의미, 최대 범위가 5

vector<vector<int>> map(N, vector<int>(N, 0));
vector<int> digits; //숫자 저장해서 6자리가 되는지 검사

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void DFS(int x, int y, int num, int length)
{
	if (length == 6)
	{
		digits.push_back(num);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
		{
			DFS(nextX, nextY, (num * 10 + map[nextY][nextX]), length + 1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			DFS(j, i, map[i][j], 1); //(x,y), length 순으로 넣는다
		}
	}

	std::sort(digits.begin(), digits.end());
	digits.erase(unique(digits.begin(), digits.end()), digits.end());

	std::cout << digits.size() << std::endl;
	return 0;
}