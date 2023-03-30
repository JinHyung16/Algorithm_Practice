#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 �ּ� �� - �ڷ� ���� �˰���
/// �������� �ּ����� �̿��϶� ������, ������ ��� ������ �ʿ�� ����
/// priority_queue���� greater�� ���������� �ǹ�
/// </summary>

using namespace std;

vector<string> noListen;

int main(void)
{
	FastIO;
	
	priority_queue<int, vector<int>, std::greater<int>> pq;

	int N(0); //������ ���� N
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		std::cin >> x;
		if (x == 0)
		{
			if (pq.empty())
			{
				std::cout << 0 << "\n";
			}
			else
			{
				std::cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}
	return 0;
}