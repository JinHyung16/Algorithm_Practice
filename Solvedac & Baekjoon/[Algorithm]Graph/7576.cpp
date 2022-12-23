#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Gold4 �丶�� - Graph �˰���
/// �丶�䰡 �� �ʹ°� ������ BFS�� ����
/// DFS�� ���� �Ǵµ�, ������ �ּ� �ϼ��� ������ ������ BFS�� �̿�
/// �ֳĸ� ���� �丶�� �ֺ��� �켱������ �����ϱ� �����̴�.
/// stack�� ��� ��������� queue�� ������ BFS�� �̿��ߴ�.
/// DFS���� �켱���� ť�� �ᵵ �ɰŰ����ϴ�.
/// </summary>


using namespace std;

int w(0), h(0); //w�� ���� Mĭ h�� ���� Nĭ

vector<vector<int>> tomatoBox(1001, vector<int>(1001, 0));
queue<pair<int, int>> ripenTomato; //���� �丶�� ����

//right -> down -> left -> up ����
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
	
	//y�� x�� ������ ����
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			std::cin >> tomatoBox[i][j];
			if (tomatoBox[i][j] == 1)
			{
				//���� �丶�䰡 ���Դٸ� ���� (���� ������ ����, ���� ������)
				ripenTomato.push(make_pair(j, i));
			}
		}
	}

	BFS();

	//�丶�䰡 ���������� �ּ� �ɸ� �ϼ� �����ϱ�
	int ripenCount(0); //������ �丶�� ����
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (tomatoBox[i][j] == 0)
			{
				//������ �丶�䰡 �ִٸ� -1����ϰ� ������
				std::cout << -1 << std::endl;
				return 0;
			}

			if (ripenCount < tomatoBox[i][j])
			{
				ripenCount = tomatoBox[i][j];
			}
			
		}
	}

	//��� ����غ��� 1�� �� ���� ���ͼ� -1 �����.
	std::cout << ripenCount - 1 << std::endl;
	return 0;
}