#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold3 아기 상어 - Graph 알고리즘
/// BFS를 이용해 해결하면 된다.
/// 이때 BFS를 상어가 맵 안에있는 먹을 수 있는 물고기들을 먹을 수 있을때까지 계속 호출해줘야한다.
/// 또한 BFS 호출하여 먹이를 먹을때마다 변하는 상어의 크기도 받아야한다.
/// 문제에서 위쪽 좌측을 가장 중요시하게 이야기했다. 즉 갈 수 있는 방향이 많다면 위쪽 좌측을 먼저 돌도록 dx, dy를 설정한다.
/// </summary>

using namespace std;

vector<vector<int>> fishBowl(20, vector<int>(20, 0));
vector<vector<bool>> visited(20, vector < bool>(20, false));

int N(0); //공간의 크기 N
int sharkX(0), sharkY(0); //상어의 시작 위치
int sharkSize = 2;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int eatCount = 0;
int totalEatTime = 0; //총 걸린시간
bool isEat = false; //물고기를 먹었는지
bool isEnd = false; //물고기를 아예 못 먹는 경우인지

void ResetArray()
{
	for (int i = 0; i < visited.size(); i++)
	{
		for (int j = 0; j < visited.size(); j++)
		{
			visited[i][j] = false;
		}
	}
}
void BFS(int x, int y, int size)
{
	queue<pair<pair<int, int>, int>> q; //상어 좌표와 걸린 시간 저장
	q.push(make_pair(make_pair(x, y), 0));
	visited[y][x] = true;
	int oneEatTime = 0; //한마리 먹는데 걸리는 시간 담기
	while (!q.empty())
	{
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int curTime = q.front().second;
		q.pop();
		if (0 < fishBowl[curY][curX] && fishBowl[curY][curX] < size && oneEatTime == curTime)
		{
			//상호 위치에 따라 먹을 수 있는 좌표가 많으면 가장 위쪽을 먼저 그다음 왼쪽을 먹어야 한다
			if (curY < sharkY || (curX < sharkX && curY == sharkY))
			{
				sharkX = curX;
				sharkY = curY;
				continue;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N && !visited[nextY][nextX]) //어항에서 움직일 수 있는 경우
			{
				if (fishBowl[nextY][nextX] <= sharkSize) //물고기가 있는 곳을 지나치거나 먹을 수 있는 경우
				{
					if (0 < fishBowl[nextY][nextX] && fishBowl[nextY][nextX] < sharkSize && !isEat)
					{
						//현재 칸 물고기를 먹을 수 있는데 아직 먹지 않았다면 먹는다.
						isEat = true;
						sharkX = nextX;
						sharkY = nextY;
						oneEatTime = curTime + 1;
						totalEatTime += oneEatTime;
					}
					else
					{
						q.push({ { nextX, nextY }, curTime + 1 });
						visited[nextY][nextX] = true;
					}
				}
			}
		}
	}
}

int main(void)
{
	FastIO;
	
	std::cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> fishBowl[i][j];
			if (fishBowl[i][j] == 9)
			{
				sharkX = j;
				sharkY = i;
				fishBowl[i][j] = 0;
			}
		}
	}

	while (!isEnd)
	{
		ResetArray();
		BFS(sharkX, sharkY, sharkSize);
		if (isEat)
		{
			isEat = false;
			eatCount += 1;
			fishBowl[sharkY][sharkX] = 0;
			if (eatCount == sharkSize)
			{
				//물고기 먹은 횟수에 맞춰 상어 사이즈 증가시키기
				sharkSize += 1;
				eatCount = 0;
			}
		}
		else
		{
			isEnd = true;
		}
	}

	std::cout << totalEatTime << "\n";
	return 0;
}