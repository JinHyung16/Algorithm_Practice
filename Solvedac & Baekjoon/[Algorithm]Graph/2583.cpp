#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���� ���ϱ� - Graph �˰���
/// �Է¿��� x��ǥ�� y��ǥ�� �� ��������.
/// K�ٿ� ���� x1, y1, x2, y2 ������� ĥ�� ��ǥ�� ���۰� �� ������ ���´�. 1�� ĥ�� ������ ���� 2�� �� �����̴�.
/// �� ĥ������, ĥ�� ���� BFS�� ���� ��ĥ���� ���� �������� �����¿츦 ���鼭 ��ġ���� ������ ������ ���Ѵ�.
/// �̴� ĥ���� ������ ���� �� �̻� �� �� ������ ���� ����.
/// BFS�� �ʱ� �־��� ���� ũ�� y�� M, x�� N��ŭ ����. BFS����� ���ÿ� BFS ���� Ƚ���� ������ ������ ������ �ǹ�
/// BFS ���� �Լ� ������ ������ ���� �̾��� ������ ã��������, �ش� ������ ���� ������Ű�� while�� �� ���� ������ ������ ���̸� areaVec�� ��Ƶд�.
/// ���� ��½� ��ü ������ ������ ������ ����ϰ�, �� ������ ���̴� ������������ ����Ѵ�.
/// </summary>

using namespace std;

int M(0), N(0), K(0); //y��ǥ M, x��ǥ N, K���� ���簢��
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

		//ĥ�� ������ ���ۺ��� �� �������� ���鼭 1�� ĥ�Ѵ�.
		for (int y = y1; y < y2; y++)
		{
			for (int x = x1; x < x2; x++)
			{
				region[y][x] = 1;
			}
		}
	}

	int isolateRegionCnt(0); //������ ������ ��
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