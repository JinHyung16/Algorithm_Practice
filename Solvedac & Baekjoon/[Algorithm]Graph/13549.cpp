#include<iostream>
#include<vector>
#include<queue>


#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Gold5 ���ڲ��� 3 - Graph �˰���
/// BFS�� ��� ������ ����ġ�� �����ϴٴ� ������ �ִµ�,
/// �������� �����̵��� 0��, �̵��� 1�ʷ� �����̵��� �켱 ������ �� ����.
/// �켱 ���� ť�� �ð��� ���� ��ġ�� �ִ´�.
/// �� ��, �ʱ� ���� {time, start} = {0, N}���� �ִ´�.
/// �� �� 3���� if���� ���� �����̴µ� x * 2 -> x + 1 -> x - 1 ������� if���� �ְ� �� �����̴�
/// ����� ���� �ð��� time �Ǵ� time + 1�� �ִ´�.
/// </summary>

const int maxMovePos = 100001;

int visited[100001] = { false, };
int minMoveTime = 0;

void BFS(int start, int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	visited[start] = true;

	while ( !pq.empty() )
	{
		int time = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if ( cur == end )
		{
			minMoveTime = time;
		}

		if ( cur * 2 < maxMovePos && !visited[cur * 2] )
		{
			pq.push(make_pair(time, cur * 2));
			visited[cur * 2] = true;
		}

		if ( cur + 1 < maxMovePos && !visited[cur + 1] )
		{
			pq.push(make_pair(time + 1, cur + 1));
			visited[cur + 1] = true;
		}

		if ( 0 <= cur - 1 && !visited[cur - 1] )
		{
			pq.push(make_pair(time + 1, cur - 1));
			visited[cur - 1] = true;
		}
	}

}

int main(void)
{
	FastIO;

	int N = 0, K = 0; //������ ��ġ N, ���� ��ġ K
	cin >> N >> K;

	BFS(N, K);
	cout << minMoveTime << "\n";
	return 0;
}