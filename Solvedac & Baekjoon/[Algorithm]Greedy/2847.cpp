#include<iostream>
#include<algorithm>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ������ ���� ������ - �׸��� �˰���
/// ���� �� �Է� �ް� �ڿ������� for���� ����.
/// ���� ���� �� ���� ���� ���� �� ũ�� 1�� ��� ���ָ鼭 �� �� ������ ī�����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0; //������ �� N
	std::cin >> N;
	vector<int> inputLevel(N, 0);

	for ( int i = 0; i < N; i++ )
	{
		std::cin >> inputLevel[i];
	}

	int cnt = 0;
	for ( int i = N - 1; 0 < i; i-- )
	{
		while ( inputLevel[i] <= inputLevel[i - 1] )
		{
			inputLevel[i - 1] -= 1;
			cnt++;
		}
	}

	std::cout << cnt << "\n";
	return 0;
}	