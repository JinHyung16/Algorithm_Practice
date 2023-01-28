#include<iostream>
#include<vector>
#include<queue>

typedef long long ll;

/// <summary>
/// Silver2 A->B - Graph �˰���
/// BFS�� �̿��� Ǯ��
/// queue���ٰ� ������ ��Ƶθ鼭 pop���Ѱ���
/// �̶� while���� ������ �� �� queue�� ����� ��,
/// ��� ����� �����ߴ��� ���ߴ����� ���� return�� �ٸ����Ѵ�.
/// �̶� pair���� ������ų A�� ������Ų Ƚ���� ���� �����صд�.
/// </summary>

using namespace std;

int BFS(ll a, ll b)
{
	queue<pair<ll, ll>> q;
	q.push(make_pair(a, 1)); //A�� �ʱ⿡�� ������Ų Ƚ���� 1�̴�. �ֳĸ� ���ǿ��� ������ +1�ؼ� ����ϴϱ�

	while (!q.empty())
	{
		//cur.first�� A�� �ǹ�, cur.second�� ������ų������ 1�� �����ؼ� ����
		pair<ll, ll> cur = q.front();
		q.pop();

		if (cur.first == b)
		{
			//������Ű�� A�� B�� �������ٸ�, ������Ų Ƚ�� ����
			return cur.second;
		}

		//2�� ���ؼ� ��ȯ��Ű�� ����
		if (cur.first * 2 <= b)
		{
			q.push({ cur.first * 2, cur.second + 1 });
		}

		//1�� ���� �����ʿ� �߰��ϸ� �ᱹ �ڸ����� ��ĭ �����ϰ� 1�� �ٴ°Ŵ�
		if ((cur.first * 10) + 1 <= b)
		{
			q.push({ (cur.first * 10) + 1, cur.second + 1 });
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	ll A(0), B(0); //A�� B�� �ٲ���Ѵ�
	std::cin >> A >> B;
	
	std::cout << BFS(A, B) << std::endl;
	return 0;
}