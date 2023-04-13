#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 DSLR - �׷��� �˰���
/// D: D �� n�� �� ��� �ٲ۴�. ��� ���� 9999 ���� ū ��쿡�� 10000 ���� ���� �������� ���Ѵ�. �� ��� ��(2n mod 10000)�� �������Ϳ� �����Ѵ�.
/// S: S �� n���� 1 �� �� ��� n - 1�� �������Ϳ� �����Ѵ�.n�� 0 �̶�� 9999 �� ��� �������Ϳ� ����ȴ�.
/// L: L �� n�� �� �ڸ����� �������� ȸ������ �� ����� �������Ϳ� �����Ѵ�.�� ������ ������ �������Ϳ� ����� �� �ڸ����� ������� d2, d3, d4, d1�� �ȴ�.
/// R: R �� n�� �� �ڸ����� ���������� ȸ������ �� ����� �������Ϳ� �����Ѵ�.�� ������ ������ �������Ϳ� ����� �� �ڸ����� ������� d4, d1, d2, d3�� �ȴ�.
/// 
/// BFS�� �̿��� start���� �� DSLR�� ������ �����ϸ鼭 pair�� �ι�° ������ �ش� ������ ����ƴٸ� �� �´� ���� ���ĺ� "D, S, L, R"�� �ϳ��� �ִ´�.
/// �̷��� �ݺ��ϸ鼭 start == end�� �Ǹ� ���� ����� ���ڿ����� ��ȯ�Ѵ�.
/// </summary>

using namespace std;

vector<bool> visited(10001, false);

void ResetVisited()
{
	for (int i = 0; i < visited.size(); i++)
	{
		visited[i] = false;
	}
}

string BFS(int start, int end)
{
	queue<pair<int, string>> q;
	q.push(make_pair(start, ""));
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		string commend = q.front().second;
		q.pop();

		if (cur == end)
		{
			return commend;
		}

		int next = cur * 2;
		if (9999 < next)
		{
			next %= 10000;
		}
		if (!visited[next])
		{
			visited[next] = true;
			q.push({ next, commend + "D" });
		}

		next = cur - 1;
		if (next < 0)
		{
			next = 9999;
		}
		if (!visited[next])
		{
			visited[next] = true;
			q.push({ next, commend + "S" });
		}

		next = (cur % 1000) * 10 + (cur / 1000);
		if (!visited[next])
		{
			visited[next] = true;
			q.push({ next, commend + "L" });
		}

		next = (cur % 10) * 1000 + (cur / 10);
		if (!visited[next])
		{
			visited[next] = true;
			q.push({ next, commend + "R" });
		}
	}
}

int main(void)
{
	FastIO;
	
	int T(0); //�׽�Ʈ ���̽��� ���� T
	int A(0), B(0); //�� ���� ���� A, B
	
	std::cin >> T;
	while (T--)
	{
		std::cin >> A >> B;
		ResetVisited();
		string result = BFS(A, B);
		std::cout << result << "\n";
	}
	return 0;
}