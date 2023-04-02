#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 �ִ� �� - �ڷ� ���� �˰���
/// priority_queue<int> pq �� �ǹ̴� priority_queue<int, vector<int>, std::less<int>> pq �� ���� �ǹ̴�.
/// �⺻�� ������������ �����ؼ� �켱 ���� ť�� ����� ���� ���ǿ� ���� �ذ��Ѵ�.
/// </summary>

using namespace std;

vector<bool> visited(1000001, false);

int main(void)
{
	FastIO;

	int N(0); //������ ���� N
	std::cin >> N;

	priority_queue<int> pq;

	while (N--)
	{
		int input(0);
		std::cin >> input;
		if (input == 0)
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
			pq.push(input);
		}
		
	}
	
	return 0;
}