#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 ���� �켱���� ť - �ڷ� ���� �˰���
/// �켱 ���� ť�� �̿���, ���� ū ���� ���� ���� �� ������� ���� �����صд�.
/// ���� char�� I��� pq�� ������, D��� pq���� �ش� ���ڸ� ����.
/// 
/// maxPQ�� minPQ���� ��ȿ���� �ʴ� ���ڸ� �����ϴ� ������, ���� �ΰ��� �켱���� ť�� ����ϴٺ���
/// �ݴ��ʿ��� �̹� ���������� �ִ� ���� ã�� ���߱� �����̴�.
/// 
/// while�� ���ǿ��� !.empty()�� if������ !visited�ϸ� ������ ����.
/// ������ ���� �������� �ѹ��� �˻��ؼ� �ȵ��ų� �� �� �˻��ϸ鼭 ���ų��� ���̰���.
/// 
/// ���� pair�� ������ first �� n�� �������� ���ĵǴϱ� top().first���� second���� �� �ľ�����
/// </summary>

using namespace std;

vector<bool> visited(1000001, false);

int main(void)
{
	FastIO;

	int T(0); //T���� �׽�Ʈ
	std::cin >> T;

	while(T--)
	{
		int N(0); //�־��� ���ڿ� ���� ����
		std::cin >> N;
		priority_queue<pair<int, int>> maxPQ;
		priority_queue<pair<int, int>, vector<pair<int,int>>, std::greater<pair<int, int>>> minPQ; //pair�� first�� �������� ���ĵȴ�.

		for (int i = 0; i < N; i++)
		{
			char c;
			int n;
			std::cin >> c >> n;

			if (c == 'I')
			{
				maxPQ.push({ n, i });
				minPQ.push({ n, i });
				visited[i] = true;
			}
			else
			{
				if (n == 1)
				{
					//��ȿ���� ���� ������ �� ����
					while (!maxPQ.empty() && !visited[maxPQ.top().second])
					{
						maxPQ.pop();
					}

					if (!maxPQ.empty())
					{
						visited[maxPQ.top().second] = false;
						maxPQ.pop();
					}
				}
				else
				{
					while (!minPQ.empty() && !visited[minPQ.top().second])
					{
						minPQ.pop();
					}

					if (!minPQ.empty())
					{
						visited[minPQ.top().second] = false;
						minPQ.pop();
					}
				}
			}
		}

		while (!maxPQ.empty() && !visited[maxPQ.top().second])
		{
			maxPQ.pop();
		}
		while (!minPQ.empty() && !visited[minPQ.top().second])
		{
			minPQ.pop();
		}

		if (minPQ.empty() && maxPQ.empty())
		{
			std::cout << "EMPTY" << "\n";
		}
		else
		{
			std::cout << maxPQ.top().first << " " << minPQ.top().first << "\n";
		}
	}
	
	return 0;
}