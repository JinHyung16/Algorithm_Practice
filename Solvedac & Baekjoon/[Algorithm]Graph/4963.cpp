#include<iostream>
#include<vector>
#include<stack>

/// <summary>
/// Silver2 ���� ���� - Graph �˰���
/// DFS�� �̿��� Ǯ��
/// �밢�� �����ӱ��� ����� 8���� �������� ���������� �ȴ�.
/// stk���� ���� ���� ���� �־�ΰ� ����ϸ� �ȴ�.
/// </summary>

using namespace std;

const int MAX_SIZE = 52;

int width(0), height(0); //������ �ʺ� w, ���� h
vector<vector<int>> map(MAX_SIZE, vector<int>(MAX_SIZE, 0)); //������ �ʺ�� ������ �ִ� ������ 50�����̹Ƿ�
vector<vector<bool>> visited(MAX_SIZE, vector<bool>(MAX_SIZE, false));
int landCount = 0;

//�����¿� �밢�� 8���� �ǹ�
int dw[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dh[8] = { 0, 1, 1 ,1, 0, -1, -1, -1 };

//�迭�� �ʱ�ȭ ���ش�. (���� �ؾ��ϴ�)
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
	stk.push(make_pair(w, h)); //w,h ������ ����

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
				//���� �ٱ� �����̸� �н�
				continue;
			}

			if (!visited[nextH][nextW] && map[nextH][nextW] == 1)
			{
				//�湮���� �ʾư� ������ ���
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
				//1�� ��, 0�� �ٴٸ� �ǹ�
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