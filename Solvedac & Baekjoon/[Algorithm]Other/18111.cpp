#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 마인크래프트 - 브루트포스 알고리즘
/// 블럭을 제거하여 인벤에 넣는 시간은 2초
/// 블럭을 꺼내 좌표 가장 위에 올리는데 1초
/// 
/// 땅의 최소 높이부터 최대 높이까지 모든 땅들을 보면서
/// 인벤에서 꺼내는 횟수와 땅을 제거하는 횟수를 적어놓는다.
/// 인벤에서 꺼낸횟수 <= (B+땅에서 제거하는 횟수)라는 의미는
/// 인벤에서 꺼낸 블럭보다 (기존 갖고있는 블럭수 + 제거하여 인벤에 넣은 수)를 의미한다.
/// 이때 minTime을 구하고 이때의 h값을 구한다.
/// </summary>

using namespace std;

vector<vector<int>> ground(500, vector<int>(500,0));

int main(void)
{
	FastIO;
	
	int N(0), M(0), B(0); //세로 N, 가로 M, 시작시 인벤에 들어있는 블록 개수 B
	std::cin >> N >> M >> B;

	int maxHeight(256); //땅의 최대 높이
	int minTime(987654321); //땅을 제거하고 쌓는데 걸린 최종 최소 시간
	int mostHeightGround(0); //가장 높은 땅의 높이

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> ground[i][j];
		}
	}

	for (int h = 0; h <= maxHeight; h++)
	{
		int subToInven = 0; //인벤에서 꺼낸 횟수
		int removeHeight = 0; //땅을 제거한 횟수
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int height = ground[i][j] - h;
				if (0 < height)
				{
					//땅이 높다면 땅을 제거한다
					removeHeight += height;
				}
				else if(height < 0)
				{
					//땅이 낮다면
					subToInven -= height;
				}
			}
		}

		if (subToInven <= (B + removeHeight))
		{
			int time = (removeHeight * 2) + subToInven;
			if (time <= minTime)
			{
				minTime = time;
				mostHeightGround = h;
			}
		}
	}

	std::cout << minTime << " " << mostHeightGround << "\n";

	return 0;
}