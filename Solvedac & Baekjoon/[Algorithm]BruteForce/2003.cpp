#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ������ �� 2 - ���Ʈ���� �˰���
/// sequence �迭�� ������ �����Ѵ�.
/// �� �� 2�� for���� ����, sum�� ���� �����ϰ�,
/// sum == M�� ��� ����� ���� ������Ű��, sum = 0���� �ʱ�ȭ �� �� break�Ѵ�.
/// �̶� ���� for���� �� ���Ҵµ� sum != 0�̶�� �׻� sum = 0���� �ʱ�ȭ ���ش�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, M = 0; //N���� ���� �� ������ �� M
	std::cin >> N >> M;

	vector<int> sequence(N + 1, 0); //sequence �迭
	int sum = 0; //sequence[i] + sequence[j]�� ��
	int cnt = 0; //sum == M�� �����ϴ� ����� �� ����

	for ( int i = 0; i < N; i++ )
	{
		std::cin >> sequence[i];
	}

	for ( int i = 0; i < N; i++ )
	{
		for ( int j = i; j < N; j++ )
		{
			sum += sequence[j];
			if ( sum == M )
			{
				cnt++;
				sum = 0;
				break;
			}
		}
		if ( sum != 0 )
		{
			sum = 0;
		}
	}

	std::cout << cnt << "\n";
	return 0;
}