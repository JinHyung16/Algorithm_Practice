#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 �� - �ڷᱸ�� �˰���
/// ����� �����ϴ� ��ġ�� 1�� ǥ��
/// ���� ���� ��ġ�� queue�� �̿��� push�ϰ� pop�Ѵ�.
/// ���� ���� ��ġ�� ������ �� �ڿ� ���� �޾ƾ� ������ ����� �ϴµ� ���ϴ�.
/// 
/// ���õ� �� �̵� ������ ������ ����.
/// (����1) ���� ���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��.
/// (����2) ���� �̵��� ĭ�� ����� �ִٸ�, �� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
/// (����3) ���� �̵��� ĭ�� ����� ���ٸ�, �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�.��, �����̴� ������ �ʴ´�.
/// </summary>

using namespace std;

int N(0), K(0); //������ ũ�� N, ����� ���� K
int L(0); //���� ���� ��ȯ Ƚ��

vector<vector<int>> board(101, vector<int>(101, 0));
vector<char> directionChange(10001, ' ');
vector<vector<bool>> IsSnakeBody(101, vector<bool>(101, false)); //���� ������ �ش� ��ġ�� �ִ���

//�� -> �� -> �� -> �� ������ �����̱�
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int SnackMove(int x, int y)
{
	queue<pair<int, int>> snakeBodyPos; //�� ������ ������� ����
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
			//������ �̵�
			curDirecton += 1;
			if (curDirecton == 4)
			{
				//dx[4] index�� ������ �̶� ���������� ��� ����
				curDirecton = 0;
			}
		}
		else if (directionChange[curTime] == 'L')
		{
			//���� �̵�
			curDirecton -= 1;
			if (curDirecton == -1)
			{
				//dx[-1] index�� ������ �̶� �������� ��� ����
				curDirecton = 3;
			}
		}

		//(����2)�� (����3) �κ� �����ϱ�
		if (board[nextY][nextX] == 1)
		{
			//����� �ִٸ� ��� ������� ���� ����
			board[nextY][nextX] = 0;
		}
		else
		{
			//����� ���ٸ� ���� �����
			if (IsSnakeBody[nextY][nextX])
			{
				break;
			}
			IsSnakeBody[snakeBodyPos.front().second][snakeBodyPos.front().first] = false;
			snakeBodyPos.pop();
		}

		//(����1) �����ϱ� -> �������� ������ �־��ٸ� ���߱� �ƴ϶�� ���� �־��ֱ�
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
		int X; //X�ʰ� ������
		char C; //C�������� 90�� ȸ��
		std::cin >> X >> C;
		directionChange[X] = C;
	}

	int result = SnackMove(1, 1);
	std::cout << result << "\n";

	return 0;
}