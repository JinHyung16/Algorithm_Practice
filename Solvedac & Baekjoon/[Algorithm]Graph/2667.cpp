#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ������ȣ���̱� - Graph �˰���
/// BFS�� �̿��� ���� �� ������ ������ �����ϸ� �ϳ��� ������ ���´�
/// �̶�, �밢���� �����Ѵ�.
/// ���� �Է¹����� ������� �Է¹����Ƿ�, scanf("%1d", &map[i][j])���� �ްų� char�̳� string���� �޾ƾ��Ѵ�.
/// </summary>

using namespace std;

int N(0); //������ ũ�� N(���簢��)
vector<vector<char>> map(26, vector<char>(26, ' '));
vector<vector<bool>> visited(25, vector<bool>(25, false));
vector<int> houseAmout;

//��->��->��->��� ������
int dx[4] = { 0, 0,-1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	visited[y][x] = true;

	int cnt = 0;
	cnt++;
	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
			{
				if (!visited[nextY][nextX] && map[nextY][nextX] == '1')
				{
					q.push({ nextX, nextY });
					visited[nextY][nextX] = true;
					cnt++;
				}
			}
		}
	}

	//BFS�� ���鼭 houseAmount�� index�� �ܼ��� � �ִ��� �����Ѵ�.
	houseAmout.push_back(cnt);
}

int main(void)
{
	FastIO;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && map[i][j] == '1')
			{
				//j�� x�� i�� y���� ����ؼ� �� ����
				BFS(j, i);
			}
		}
	}
	
	std::sort(houseAmout.begin(), houseAmout.end());
	std::cout << houseAmout.size() << "\n";
	for (int i = 0; i < houseAmout.size(); i++)
	{
		std::cout << houseAmout[i] << "\n";
	}
	return 0;
}