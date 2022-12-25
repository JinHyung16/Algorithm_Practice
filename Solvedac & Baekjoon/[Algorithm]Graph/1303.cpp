#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver1 전쟁-전투 - Graph 알고리즘
/// BFS를 이용해 각 팀 입장에서 실행한다.
/// 이때 중간에 팀 교체시 맵 초기화 하는거 잊지말자
/// 또한 맵에선 x가 모여야 하나의 y를 구성하니 배열 index 참조시 x y 순서 중요
/// BFS 파라메터가 x,y순인데 이중 for문은 안쪽이 x이므로 index잘 생각해서 넣자!
/// 초기화시 memset이나 fill(fill_n)사용해도 되지만
/// 나는 vector를 사용해서 그냥 for문을 통해 리셋 했다.
/// </summary>

using namespace std;

const int MAX_VAlUE = 101;
int W(0), H(0); //가로 크기 N, 세로 크기 M 의미
vector<vector<char>> charMap(MAX_VAlUE, vector<char>(MAX_VAlUE, ' '));
vector<vector<int>> intMap(MAX_VAlUE, vector<int>(MAX_VAlUE, 0));
vector<vector<bool>> visitedMap(MAX_VAlUE, vector<bool>(MAX_VAlUE, false));
vector<int> dx = { 0, 0, -1, 1 };
vector<int> dy = { 1, -1, 0, 0 };

int whiteSoldiers = 0;
int blueSoldiers = 0;
int soldier = 1;


void ResetMap()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			intMap[i][j] = 0;
			visitedMap[i][j] = false;
		}
	}
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	visitedMap[y][x] = true;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (nextX < 0 || nextX >= W || nextY < 0 || nextY >= H)
			{
				continue;
			}
			if (intMap[nextY][nextX] == 1 && !visitedMap[nextY][nextX])
			{
				visitedMap[nextY][nextX] = true;
				soldier++;
				q.push({ nextX, nextY });
			}
		}
	}


}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> W >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			std::cin >> charMap[i][j];
		}
	}

	//White 병사 전투력 측정하기
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (charMap[i][j] == 'W')
			{
				intMap[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (intMap[i][j] == 1 && !visitedMap[i][j])
			{
				BFS(j, i); //x,y순으로 넣어야한다
				whiteSoldiers += soldier * soldier;
				soldier = 1;
			}
		}
	}

	//맵 초기화 하기
	ResetMap();

	//Blue 병사 전투력 측정하기
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (charMap[i][j] == 'B')
			{
				intMap[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (intMap[i][j] == 1 && !visitedMap[i][j])
			{
				BFS(j, i); //x,y순으로 넣어야한다
				blueSoldiers += soldier * soldier;
				soldier = 1;
			}
		}
	}

	std::cout << whiteSoldiers << " " << blueSoldiers << std::endl;
	return 0;
}