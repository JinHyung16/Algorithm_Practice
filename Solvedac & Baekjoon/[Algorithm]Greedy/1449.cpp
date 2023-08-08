#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ������ �׽� - Greedy �˰���
/// 1) ���� ���� ���� �������� �Ѵ�.
/// 2) �������� ���� <= ������ ���� �ٸ� ���� ���������� �Ÿ���
///		�ʿ��� ������ ���� + 1�ϰ� ���� ��ġ�� �������Ѵ�.
/// 2)�� ������ �ݺ��� ��, ������ �������� ������ �������� �����Ƿ� +1�Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, L = 0; //���� ���� ���� ���� N, �������� ���� L
	int needTapeCnt = 0;
	std::cin >> N >> L;
	vector<int> greedy(N, 0);
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> greedy[i];
	}

	std::sort(greedy.begin(), greedy.end());
	int start = greedy[0];
	for ( int i = 1; i < N; i++ )
	{
		if ( L <= greedy[i] - start )
		{
			needTapeCnt++;
			start = greedy[i];
		}
	}
	needTapeCnt++;

	std::cout << needTapeCnt << "\n";
	return 0;
}