#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold3 �Ʊ� ��� - Graph �˰���
/// BFS�� �̿��� �ذ��ϸ� �ȴ�.
/// �̶� BFS�� �� �� �ȿ��ִ� ���� �� �ִ� �������� ���� �� ���������� ��� ȣ��������Ѵ�.
/// ���� BFS ȣ���Ͽ� ���̸� ���������� ���ϴ� ����� ũ�⵵ �޾ƾ��Ѵ�.
/// �������� ���� ������ ���� �߿���ϰ� �̾߱��ߴ�. �� �� �� �ִ� ������ ���ٸ� ���� ������ ���� ������ dx, dy�� �����Ѵ�.
/// </summary>

using namespace std;

vector<vector<int>> fishBowl(20, vector<int>(20, 0));
vector<vector<bool>> visited(20, vector < bool>(20, false));

int N(0); //������ ũ�� N
int sharkX(0), sharkY(0); //����� ���� ��ġ
int sharkSize = 2;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int eatCount = 0;
int totalEatTime = 0; //�� �ɸ��ð�
bool isEat = false; //����⸦ �Ծ�����
bool isEnd = false; //����⸦ �ƿ� �� �Դ� �������

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
	queue<pair<pair<int, int>, int>> q; //��� ��ǥ�� �ɸ� �ð� ����
	q.push(make_pair(make_pair(x, y), 0));
	visited[y][x] = true;
	int oneEatTime = 0; //�Ѹ��� �Դµ� �ɸ��� �ð� ���
	while (!q.empty())
	{
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int curTime = q.front().second;
		q.pop();
		if (0 < fishBowl[curY][curX] && fishBowl[curY][curX] < size && oneEatTime == curTime)
		{
			//��ȣ ��ġ�� ���� ���� �� �ִ� ��ǥ�� ������ ���� ������ ���� �״��� ������ �Ծ�� �Ѵ�
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

			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N && !visited[nextY][nextX]) //���׿��� ������ �� �ִ� ���
			{
				if (fishBowl[nextY][nextX] <= sharkSize) //����Ⱑ �ִ� ���� ����ġ�ų� ���� �� �ִ� ���
				{
					if (0 < fishBowl[nextY][nextX] && fishBowl[nextY][nextX] < sharkSize && !isEat)
					{
						//���� ĭ ����⸦ ���� �� �ִµ� ���� ���� �ʾҴٸ� �Դ´�.
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
				//����� ���� Ƚ���� ���� ��� ������ ������Ű��
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