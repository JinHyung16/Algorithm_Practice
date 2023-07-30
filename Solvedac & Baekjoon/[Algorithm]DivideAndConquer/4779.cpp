#include<iostream>
#include<vector>
#include<string>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ĭ��� ���� - ���� ���� �˰���
/// ���ڿ��� �־��� N�� ���� 3^N ���̴�.
/// ���� N�� 0�̸� -�� ����Ѵ�.
/// �� �� ���� ���� + ��͸� ���� (N-1)�� �����Ѵ�.
/// �׷��鼭 3^N-1���� ���� "-"��� " "�� ����Ѵ�.
/// </summary>

using namespace std;

void DivideAndConquer(int n)
{
	int stringSize = std::pow(3, n - 1);

	if ( n == 0 )
	{
		std::cout << "-";
		return;
	}

	DivideAndConquer(n - 1); //���� ���
	for ( int i = 0; i < stringSize; i++ )
	{
		std::cout << " ";
	}
	DivideAndConquer(n - 1); //���� ���
}

int main(void)
{
	FastIO;

	int N = 0; //�־��� 3^N
	while ( std::cin >> N )
	{
		DivideAndConquer(N);
		std::cout << "\n";
	}
	return 0;
}