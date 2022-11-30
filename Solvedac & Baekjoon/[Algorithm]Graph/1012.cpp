#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

/// <summary>
/// Silver2 ����� ���� - �׷��� �̷�
/// BFS�� �̿�����! �ֳĸ� ���� �����¿��� ���� 1������ Ȯ���ϸ� �Ǵϱ�!
/// queue�� pair�� �̿��Ͽ� BFS���� 2���� queue�� Ȱ���ϴ� ����� ������!
/// ���� vector�� 2���� �Ҵ� ����� ��������!
/// </summary>

int Row; //���߹��� ���� ������
int Col; //���߹��� ���� ������
vector<vector<int>> napaCabbageVec(50, vector<int>(50, 0));

void BFS(int r, int c)
{
	std::queue<pair<int, int>> bfsQueue;
	bfsQueue.push(make_pair(r, c));

	vector<int> dr(4);
	dr = { -1, 1, 0, 0 };

	vector<int> dc(4);
	dc = { 0, 0, -1, 1 };
	
	napaCabbageVec[r][c] = 0; //�ش� ��ġ�� �湮�� ������ 0���� �ʱ�ȭ ����

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