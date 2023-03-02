#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 단지번호붙이기 - Graph 알고리즘
/// BFS를 이용해 집과 집 사이의 간선이 존재하면 하나의 단지로 묶는다
/// 이때, 대각선은 제외한다.
/// 현재 입력받을때 공백없이 입력받으므로, scanf("%1d", &map[i][j])으로 받거나 char이나 string으로 받아야한다.
/// </summary>

using namespace std;

int N(0); //지도의 크기 N(정사각형)
vector<vector<char>> map(26, vector<char>(26, ' '));
vector<vector<bool>> visited(25, vector<bool>(25, false));
vector<int> houseAmout;

//상->하->좌->우로 움직임
int dx[4] = { 0, 0,-1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	visited[y][x] = true;

	int cnt = 0;
	cnt++;
	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
			{
				if (!visited[nextY][nextX] && map[nextY][nextX] == '1')
				{
					q.push({ nextX, nextY });
					visited[nextY][nextX] = true;
					cnt++;
				}
			}
		}
	}

	//BFS가 돌면서 houseAmount의 index의 단수가 몇개 있는지 저정한다.
	houseAmout.push_back(cnt);
}

int main(void)
{
	FastIO;

	std::cin >> N;
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
			if (!visited[i][j] && map[i][j] == '1')
			{
				//j가 x고 i가 y임을 기억해서 잘 넣자
				BFS(j, i);
			}
		}
	}
	
	std::sort(houseAmout.begin(), houseAmout.end());
	std::cout << houseAmout.size() << "\n";
	for (int i = 0; i < houseAmout.size(); i++)
	{
		std::cout << houseAmout[i] << "\n";
	}
	return 0;
}