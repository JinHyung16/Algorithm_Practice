#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 뱀 - 자료구조 알고리즘
/// 사과가 존재하는 위치는 1로 표시
/// 뱀의 몸통 위치는 queue를 이용해 push하고 pop한다.
/// 뱀의 몸통 위치를 받을때 맨 뒤에 값을 받아야 꼬리를 지우고 하는데 편하다.
/// 
/// 제시된 뱀 이동 조건은 다음과 같다.
/// (조건1) 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
/// (조건2) 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
/// (조건3) 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다.즉, 몸길이는 변하지 않는다.
/// </summary>

using namespace std;

int N(0), K(0); //보드의 크기 N, 사과의 개수 K
int L(0); //뱀의 방향 변환 횟수

vector<vector<int>> board(101, vector<int>(101, 0));
vector<char> directionChange(10001, ' ');
vector<vector<bool>> IsSnakeBody(101, vector<bool>(101, false)); //뱀의 몸통이 해당 위치에 있는지

//우 -> 상 -> 좌 -> 하 순서로 움직이기
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int SnackMove(int x, int y)
{
	queue<pair<int, int>> snakeBodyPos; //뱀 몸통이 어디인지 저장
	snakeBodyPos.push(make_pair(x, y));
	IsSnakeBody[y][x] = true;

	int curTime = 0;
	int curDirecton = 0;

	while (true)
	{
		curTime += 1;
		int nextX = snakeBodyPos.back().first + dx[curDirecton];
		int nextY = snakeBodyPos.back().second + dy[curDirecton];

		if (nextX < 1 || N < nextX || nextY < 1 || N < nextY)
		{
			break;
		}
		snakeBodyPos.push({ nextX, nextY });

		if (directionChange[curTime] == 'D')
		{
			//오른쪽 이동
			curDirecton += 1;
			if (curDirecton == 4)
			{
				//dx[4] index가 없으니 이때 오른쪽으로 꺽어서 시작
				curDirecton = 0;
			}
		}
		else if (directionChange[curTime] == 'L')
		{
			//왼쪽 이동
			curDirecton -= 1;
			if (curDirecton == -1)
			{
				//dx[-1] index가 없으니 이때 왼쪽으로 꺽어서 시작
				curDirecton = 3;
			}
		}

		//(조건2)와 (조건3) 부분 만족하기
		if (board[nextY][nextX] == 1)
		{
			//사과가 있다면 사과 사라지고 꼬리 멈춤
			board[nextY][nextX] = 0;
		}
		else
		{
			//사과가 없다면 꼬리 사라짐
			if (IsSnakeBody[nextY][nextX])
			{
				break;
			}
			IsSnakeBody[snakeBodyPos.front().second][snakeBodyPos.front().first] = false;
			snakeBodyPos.pop();
		}

		//(조건1) 만족하기 -> 원래부터 몸통이 있었다면 멈추기 아니라면 몸통 넣어주기
		if (IsSnakeBody[nextY][nextX])
		{
			break;
		}
		else
		{
			IsSnakeBody[nextY][nextX] = true;
		}
	}

	return curTime;
}

int main(void)
{
	FastIO;

	std::cin >> N;
	std::cin >> K;

	for (int i = 0; i < K; i++)
	{
		int row, col;
		std::cin >> row >> col;
		board[row][col] = 1;
	}

	std::cin >> L;
	for (int i = 0; i < L; i++)
	{
		int X; //X초가 지난뒤
		char C; //C방향으로 90도 회전
		std::cin >> X >> C;
		directionChange[X] = C;
	}

	int result = SnackMove(1, 1);
	std::cout << result << "\n";

	return 0;
}