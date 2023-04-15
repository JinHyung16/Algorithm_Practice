#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���� �� - �ڷᱸ�� �˰���
/// priority queue�� �̿��� ������ �ذ��Ѵ�.
/// 1. 0�� ������ �迭���� ������ ���� ���� ���� ����ϰ� �� ���� �迭���� ����
/// 2. 0�� �ƴ϶�� �迭�� x���� �ִ´�.
/// priority queue�� �̿��� ������ ������ ���� ���ڰ� �� �տ� ���� �����ϸ鼭 �ִ´�.
/// priority queue���� ����ü�� ����ϸ� ����ü ���ο��� ������ ���� �ε��� ���� �켱������ ���ϰ� �ٲ� �� �ִ�. 
/// </summary>

using namespace std;

struct absGrater 
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
		{
			//������ ���ٸ� ������ ���� �տ� ���鼭 ��������
			auto c = a > b;
			return a > b;
		}
		else
		{
			//�ƴ϶�� �׳� ���� ũ�� ������� ��������
			auto c = abs(a) > abs(b);
			return abs(a) > abs(b);
		}
	}
};

int main(void)
{
	FastIO;
	
	int N(0); //������ ���� N
	int x(0);
	priority_queue<int, vector<int>, absGrater> pq;
	std::cin >> N;
	while (N--)
	{
		std::cin >> x;
		if (x == 0)
		{
			if (!pq.empty())
			{
				std::cout << pq.top() << "\n";
				pq.pop();
			}
			else
			{
				std::cout << 0 << "\n";
			}
		}
		else
		{
			pq.push(x);
		}
	}
	return 0;
}