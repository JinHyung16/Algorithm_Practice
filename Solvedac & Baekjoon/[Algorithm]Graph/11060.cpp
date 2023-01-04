#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 ���� ���� - Graph �˰���
/// BFS�� �̿��� Ǯ��
/// DFS�� dp�� �̿��ؼ� �ּڰ��� dp�� �����ذ��鼭 Ǯ ���� ������ ����.
/// queue���� ���� ��ġ�� ������ count ����
/// </summary>

using namespace std;

vector<int> map(1001, 0); //n�� �ִ� ũ�Ⱑ 1000����
vector<bool> visited(1001, false); //�湮 ���� üũ�ϱ�
int minJumpCnt(0);

int BFS(int n)
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0] = true; //ó�� ������ �׻� true

	while (!q.empty())
	{
		int curPos = q.front().first;
		int jumpCnt = q.front().second;
		q.pop();

		if (curPos == n - 1)
		{
			return jumpCnt;
		}

		int jump = map[curPos];
		for (int i = 0; i <= jump; i++)
		{
			int nextPos = curPos + i;
			if (!visited[nextPos])
			{
				visited[nextPos] = true;
				q.push({ nextPos, jumpCnt + 1 });
			}
		}
	}

	//���� ���������� �� �� ���� ���, -1�� return�Ѵ�
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //�̷��� size 1*n

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> map[i];
	}
	
	minJumpCnt = BFS(N);

	std::cout << minJumpCnt << std::endl;

	return 0;
}