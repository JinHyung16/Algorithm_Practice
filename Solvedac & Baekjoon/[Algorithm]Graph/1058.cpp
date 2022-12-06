#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver1 ģ�� - Graph �̷�
/// �Ÿ��� 2���ϸ� ģ���� ī��������, �̶� N�� ����Ѱ� ���� ����
/// ���ΰ� ������ ģ���ΰ�쵵 ���ԵǾ ����Ǳ⿡ ������ ī���ÿ��� -1 ������ 
/// dfs, bfs�� ������ ����
/// </summary>

vector<int> friendTree[51];
vector<bool> visited(51, false);

//�Ÿ��� 2���ϸ� ģ����, �Ÿ�1�϶� �Ÿ�2�϶� �̷��� depth�� 2���� ����
void DFS(int depth, int start)
{
	visited[start] = true;
	if (depth == 2)
	{
		return;
	}
	for (int i = 0; i < friendTree[start].size(); i++)
	{
		DFS(depth + 1, friendTree[start][i]);
	}

}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		char answer;
		for (int j = 0; j < n; j++)
		{
			std::cin >> answer;
			if (answer == 'Y')
			{
				friendTree[i].push_back(j);
			}
		}
	}

	int friendCount = 0;
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		fill_n(visited.begin(), 51, false);

		DFS(0, i);
		for (int j = 0; j < n; j++)
		{
			if (visited[j] == true)
			{
				count++;
			}
		}
		//�����̶� ģ���ΰ͵� ���ԵǾ ���ư��� -1 ������
		friendCount = std::max(friendCount, count - 1);
	}

	std::cout << friendCount << std::endl;

	
	return 0;
}