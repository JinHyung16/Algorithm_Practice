#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ���� ������ - �̺� Ž�� �˰���
/// �־��� n�� ���� sqrt(n)�� �����Ͽ� �������� ã�´�.
/// �� �� sqrtNum�� �ٽ� �����Ͽ� n���� ������ sqrtNum�� 1 ������Ų �� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	long long n = 0;
	std::cin >> n;

	long long sqrtNum = 0;
	sqrtNum = std::sqrt(n);

	if ( (sqrtNum * sqrtNum) < n )
	{
		sqrtNum += 1;
	}
	std::cout << sqrtNum << "\n";
	return 0;
}