#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 ���ϱ� ����Ŭ - ���� �˰���
/// �ʰ� ���� �ڸ��� ������, ���� �ڸ� + ���� �ڸ� ���� ���� �ڸ��� �ٽ� ���� �ڸ��� �ٲ� ������ �ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	int n, sum;
	int a, b;
	int sycle = 1;
	cin >> n;
	int m = n;

	while ( true )
	{
		a = (n / 10), b = (n % 10);
		sum = a + b;
		n = (b * 10) + (sum % 10);
		if ( m == n )
			break;
		else
			sycle++;
	}
	cout << sycle << endl;

	return 0;
}