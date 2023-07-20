#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 ���������� - ���Ʈ���� �˰���
/// number ���Ϳ� for i = 1 to N ���� i��°�� i*i ������ ���� �����صд�.
/// �� �� N���� for���� ���鼭 M�̻� N������ number[i]��° ���� ã�� sum�� minNum�� ã�´�.
/// �̶� minNum�� N�� �ִ밪�� 10000�̹Ƿ� 10000���� �ʱ�ȭ �س��´�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int M = 0, N = 0; //M�̻� N������ �ڿ���
	int sum = 0, minNum = 10000; //���� ������ ��, ���� ������ �� �ּڰ�
	std::cin >> M >> N;
	vector<int> number(N + 1);

	for ( int i = 1; i <= N; i++ )
	{
		number[i] = i * i;
	}

	for ( int i = 1; i <= N; i++ )
	{
		if ( M <= number[i] && number[i] <= N )
		{
			sum += number[i];
			minNum = std::min(minNum, number[i]);
		}
	}

	if ( sum == 0 )
	{
		std::cout << "-1" << "\n";
	}
	else
	{
		std::cout << sum << "\n" << minNum << "\n";
	}
	return 0;
}