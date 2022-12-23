#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Gold4 토마토 - Graph 알고리즘
/// 토마토가 다 익는걸 보려면 BFS로 본다
/// DFS로 봐도 되는데, 문제는 최소 일수를 빠르게 보고자 BFS를 이용
/// 왜냐면 익은 토마토 주변을 우선순위로 봐야하기 때문이다.
/// stack의 경우 선입후출로 queue를 쓰고자 BFS를 이용했다.
/// DFS에서 우선순위 큐를 써도 될거같긴하다.
/// </summary>


using namespace std;

int w(0), h(0); //w는 가로 M칸 h는 세로 N칸

vector<vector<int>> tomatoBox(1001, vector<int>(1001, 0));
queue<pair<int, int>> ripenTomato; //익은 토마토 저장

//right -> down -> left -> up 순서
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void BFS()
{
	while (!ripenTomato.empty())
	{
		int curX = ripenTomato.front().first;
		int curY = ripenTomato.front().second;
		ripenTomato.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (0 <= nextX && nextX < w && 0 <= nextY && nextY < h)
			{
				if (tomatoBox[nextY][nextX] == 0)
				{
					tomatoBox[nextY][nextX] = tomatoBox[curY][curX] + 1;
					ripenTomato.push({ nextX, nextY });
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
	
	std::cin >> w >> h;
	
	//y축 x축 순서로 저장
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			std::cin >> tomatoBox[i][j];
			if (tomatoBox[i][j] == 1)
			{
				//익은 토마토가 들어왔다면 저장 (저장 형식은 가로, 세로 순서로)
				ripenTomato.push(make_pair(j, i));
			}
		}
	}

	BFS();

	//토마토가 익을때까지 최소 걸린 일수 저장하기
	int ripenCount(0); //숙성된 토마토 개수
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (tomatoBox[i][j] == 0)
			{
				//안익은 토마토가 있다면 -1출력하고 끝내기
				std::cout << -1 << std::endl;
				return 0;
			}

			if (ripenCount < tomatoBox[i][j])
			{
				ripenCount = tomatoBox[i][j];
			}
			
		}
	}

	//결과 출력해보니 1개 더 많게 나와서 -1 해줬다.
	std::cout << ripenCount - 1 << std::endl;
	return 0;
}