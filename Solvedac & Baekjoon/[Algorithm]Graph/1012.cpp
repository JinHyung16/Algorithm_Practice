#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

/// <summary>
/// Silver2 유기농 배추 - 그래프 이론
/// BFS를 이용하자! 왜냐면 기준 상하좌우의 값이 1인지만 확인하면 되니깐!
/// queue와 pair를 이용하여 BFS에서 2차원 queue를 활용하는 방법을 익히자!
/// 또한 vector의 2차원 할당 방법도 익혀놓자!
/// </summary>

int Row; //배추밭의 가로 사이즈
int Col; //배추밭의 세로 사이즈
vector<vector<int>> napaCabbageVec(50, vector<int>(50, 0));

void BFS(int r, int c)
{
	std::queue<pair<int, int>> bfsQueue;
	bfsQueue.push(make_pair(r, c));

	vector<int> dr(4);
	dr = { -1, 1, 0, 0 };

	vector<int> dc(4);
	dc = { 0, 0, -1, 1 };
	
	napaCabbageVec[r][c] = 0; //해당 위치는 방문한 곳으로 0으로 초기화 진행

	while (!bfsQueue.empty())
	{
		int pr = bfsQueue.front().first;
		int pc = bfsQueue.front().second;

		bfsQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			int newRow = pr + dr[i];
			int newCol = pc + dc[i];
			
			if (0 <= newRow && newRow < Row && 0 <= newCol && newCol < Col)
			{
				if (napaCabbageVec[newRow][newCol] == 1)
				{
					napaCabbageVec[newRow][newCol] = 0;
					bfsQueue.push(make_pair(newRow, newCol));
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int testCase = 0;
	std::cin >> testCase;
	
	int napaCabbageCount = 0;

	for (int i = 0; i < testCase; i++)
	{
		std::cin >> Row >> Col >> napaCabbageCount;
		int r = 0, c = 0;
		for (int j = 0; j < napaCabbageCount; j++)
		{
			std::cin >> r >> c;
			napaCabbageVec[r][c] = 1;
		}

		int earthWormCount = 0;
		for (int px = 0; px < Row; px++)
		{
			for (int py = 0; py < Col; py++)
			{
				if (napaCabbageVec[px][py] == 1)
				{
					BFS(px, py);
					earthWormCount++;
				}
			}
		}
		std::cout << earthWormCount << std::endl;
	}

	return 0;
}