#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 영역 구하기 - Graph 알고리즘
/// 입력에서 x좌표와 y좌표를 잘 생각하자.
/// K줄에 걸쳐 x1, y1, x2, y2 순서대로 칠할 좌표의 시작과 끝 지점이 들어온다. 1이 칠할 지점의 시작 2가 끝 지점이다.
/// 다 칠했으면, 칠한 맵을 BFS를 통해 안칠해진 현재 지점에서 상하좌우를 보면서 안치해진 영역의 개수를 구한다.
/// 이는 칠해진 영역이 나와 더 이상 갈 수 없을때 까지 돈다.
/// BFS를 초기 주어진 맵의 크기 y축 M, x축 N만큼 돈다. BFS실행과 동시에 BFS 실행 횟수는 독립된 영역의 갯수를 의미
/// BFS 실행 함수 내에서 독립된 땅의 이어진 면적을 찾을때마다, 해당 면적의 값을 증가시키고 while을 다 돌면 독립된 영역의 넓이를 areaVec에 담아둔다.
/// 최종 출력시 전체 독립된 영역의 갯수를 출력하고, 각 영역의 넓이는 오름차순으로 출력한다.
/// </summary>

using namespace std;

int M(0), N(0), K(0); //y좌표 M, x좌표 N, K개의 직사각형
vector<vector<int>> region(101, vector<int>(101, 0));

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector<int> areaVec;

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	region[y][x] = 1;
	int regionArea = 1;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M && region[nextY][nextX] == 0)
			{
				region[nextY][nextX] = 1;
				regionArea++;
				q.push(make_pair(nextX, nextY));
			}
		}
	}
	areaVec.push_back(regionArea);
}

int main(void)
{
	FastIO;
	
	std::cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int x1(0), y1(0), x2(0), y2(0);
		std::cin >> x1 >> y1 >> x2 >> y2;

		//칠할 지점의 시작부터 끝 지점까지 돌면서 1로 칠한다.
		for (int y = y1; y < y2; y++)
		{
			for (int x = x1; x < x2; x++)
			{
				region[y][x] = 1;
			}
		}
	}

	int isolateRegionCnt(0); //독립된 영역의 수
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (region[i][j] == 0)
			{
				BFS(j, i);
				isolateRegionCnt++;
			}
		}
	}

	std::cout << isolateRegionCnt << "\n";
	
	if (0 < areaVec.size())
	{
		std::sort(areaVec.begin(), areaVec.end());
	}
	for (int i = 0; i < areaVec.size(); i++)
	{
		std::cout << areaVec[i] << " ";
	}
	std::cout << "\n";

	return 0;
}