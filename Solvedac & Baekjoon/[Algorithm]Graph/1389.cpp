#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 �ɺ� �������� 6�ܰ� ��Ģ - �׷��� �˰���
/// BFS �Ǵ� �÷��̵�-�ͼ� �˰����� �̿��� Ǯ �� �ִ�.
/// 
/// BFS�� �̿��� i��° ����� �������� ģ������ �ƴ��� �Ǵ���
/// BFS���� i��°�� ģ���ΰ� queue�� �ְ�, �ش� queue���� �ٽ� ģ���ΰ� ã�Ƽ�
/// ���������� ó�� ���� i -> i�� ģ�� -> i�� ģ���� ģ�� -> ... �̷������� i�� �ɺ� �������� ���� ã�´�.
/// i��° ���� ã�� �ɺ� �������� ���� ���� �ּҰ��� ���ذ��鼭 i~N������ ����� �ɺ� �������� ���� �ּ��� ����� ã�� true�� ��ȯ
/// ���� mian()���� ������ result = i�� BFS���� ã�� �ɺ� �������� ���� ���� ���� ����� �ǹ�
/// </summary>

using namespace std;

int N(0), M(0); //������ �� N, ģ���� �� M
vector<vector<int>> relation(101, vector<int>(101, 0));
vector<bool> visited(101, false);
vector<int> KevinCntVec(101, 0);
int kevinMin = 987654321;


void Reset()
{
	for (int i = 0; i < 101; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < 101; i++)
	{
		KevinCntVec[i] = 0;
	}
}
bool BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (!visited[i] && relation[cur][i] == 1)
			{
				visited[i] = true;
				KevinCntVec[i] = KevinCntVec[cur] + 1;
				q.push(i);
			}
		}
	}

	//ex) 1���� ó�� ������ �������� 1->3->2�ϱ� ���⼱ 1->3 1�� + 3->2 1�� �̷��� ���ؼ� 2�� �����.
	int kvSum = 0;
	for (int i = 1; i <= N; i++)
	{
		kvSum += KevinCntVec[i];
	}

	if (kvSum < kevinMin)
	{
		kevinMin = kvSum;
		return true;
	}
	return false;
}

int main(void)
{
	FastIO;

	std::cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a(0), b(0);
		std::cin >> a >> b;
		relation[a][b] = 1;
		relation[b][a] = 1;
	}

	int result(0);

	for (int i = 1; i <= N; i++)
	{
		//i��° ģ������ �ƴ����� �Ǵ��Ѵ�.
		if (BFS(i))
		{
			result = i;
		}
		Reset();
	}

	std::cout << result << "\n";
	return 0;
}