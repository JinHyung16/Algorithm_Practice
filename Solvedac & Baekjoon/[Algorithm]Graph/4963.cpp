#include<iostream>
#include<vector>
#include<stack>

/// <summary>
/// Silver2 섬의 개수 - Graph 알고리즘
/// DFS를 이용한 풀이
/// 대각선 움직임까지 고려해 8개의 방향으로 움직여보면 된다.
/// stk에는 다음 갔던 길을 넣어두고 사용하면 된다.
/// </summary>

using namespace std;

const int MAX_SIZE = 52;

int width(0), height(0); //지도의 너비 w, 높이 h
vector<vector<int>> map(MAX_SIZE, vector<int>(MAX_SIZE, 0)); //지도의 너비와 높이의 최대 범위가 50이하이므로
vector<vector<bool>> visited(MAX_SIZE, vector<bool>(MAX_SIZE, false));
int landCount = 0;

//상하좌우 대각선 8방향 의미
int dw[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dh[8] = { 0, 1, 1 ,1, 0, -1, -1, -1 };

//배열들 초기화 해준다. (재사용 해야하니)
void ResetValue()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}

	landCount = 0;
}

void DFS(int w, int h)
{
	stack<pair<int, int>> stk;
	stk.push(make_pair(w, h)); //w,h 순으로 저장

	visited[h][w] = true;
	while (!stk.empty())
	{
		int curW = stk.top().first;
		int curH = stk.top().second;
		stk.pop();

		for (int i = 0; i < 8; i++)
		{
			int nextW = curW + dw[i];
			int nextH = curH + dh[i];
			if (nextW < 0 || width <= nextW || nextH < 0 || height <= nextH)
			{
				//지도 바깥 영역이면 패스
				continue;
			}

			if (!visited[nextH][nextW] && map[nextH][nextW] == 1)
			{
				//방문하지 않아고 육지인 경우
				stk.push({ nextW, nextH });
				visited[nextH][nextW] = true;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true)
	{
		ResetValue();

		std::cin >> width >> height;
		if (width == 0 && height == 0)
		{
			break;
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				//1은 땅, 0은 바다를 의미
				std::cin >> map[i][j];
			}
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (map[i][j] == 1 && !visited[i][j])
				{
					DFS(j, i);
					landCount++;
				}
			}
		}

		std::cout << landCount << std::endl;
	}
	return 0;
}