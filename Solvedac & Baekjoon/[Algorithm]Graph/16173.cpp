#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver4 점프왕 쩰리(Small) - Graph 알고리즘
/// BFS를 이용한 풀이
/// 항상 2차원 배열에선 가로(x)가 모여야 하나의 세로(y)가 되므로 배열 인덱싱을 잘하자!
/// 기존 BFS에서 움직이는 방향만큼 움직이는데 여기에 map에 적힌 숫자만큼 움직이니 * 해주자
/// </summary>

using namespace std;

int N(0); //게임 구역의 크기 N
vector<vector<int>> map(3, vector<int>(3, 0)); //N의 최대 범위가 3이기 때문
vector<vector<bool>> visited(3, vector<bool>(3, false)); //방문했는지 체크

//x축 y축으로 이동하는 방향을 의미하는데 아래와 오른쪽으로만 이동 가능하다
vector<int> dx = { 0, 1 };
vector<int> dy = { 1, 0 };

bool BFS()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0)); //x y 좌표 순으로 저장

	visited[0][0] = true;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		if (map[curY][curX] == -1)
		{
			//도착지점 도달시 게임 끝
			return true;
		}

		for (int i = 0; i < 2; i++)
		{
			int nextX = curX + dx[i] * map[curY][curX];
			int nextY = curY + dy[i] * map[curY][curX];

			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
			{
				//젤리가 맵 위에 있는경우
				if (!visited[nextY][nextX])
				{
					//방문한 적이 없다면 방문
					visited[nextY][nextX] = true;
					q.push({ nextX, nextY });
				}
			}
		}
	}

	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> map[i][j];
		}
	}

	if (BFS())
	{
		std::cout << "HaruHaru" << std::endl;
	}
	else
	{
		std::cout << "Hing" << std::endl;
	}

	return 0;
}