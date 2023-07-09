#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 ���û ���� ������ - ������ �˰���
/// �������̶� 1�Ϻ��� K�ϱ��� ������, ���� ���� ���簪�� ���� �����س��� ���� ���Ѵ�.
/// ex) 1�Ϻ��� 5�ϱ��� �������� ���س���, 3~5�� ������ �������� ����ϰ� ������
/// 5�ϱ����� ������ - 2�ϱ����� �������� ���� ���Ѵ�.
/// �ֳ��ϸ� 1~3�ϱ��� �����հ� 1~5�ϱ����� �������� 1~2�ϱ����� �������� �ߺ��Ǳ� �����̴�.
/// �̷������� ������ �����Ѵ�.
/// temperature vector�� �̸� �������� �����صд�.
/// K�Ϻ��� N�ϱ��� for���� ���鼭, i�� �����տ� i-k���� �������� ���� max������ ũ�� �̸� ��ü�Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0, K = 0; //�µ��� ������ ��ü ��¥ N, ���� ���ϱ� ���� �������� ��¥�� �� K
	std::cin >> N >> K;

	vector<int> temperature(N + 1, 0);

	for ( int i = 1; i <= N; i++ )
	{
		int input = 0;
		std::cin >> input;
		temperature[i] = input + temperature[i - 1];
	}

	int maxResult = -987654321;
	for ( int i = K; i <= N; i++ )
	{
		int temp = temperature[i] - temperature[i - K];
		if ( maxResult < temp )
		{
			maxResult = temp;
		}
	}

	std::cout << maxResult << "\n";
	return 0;
}