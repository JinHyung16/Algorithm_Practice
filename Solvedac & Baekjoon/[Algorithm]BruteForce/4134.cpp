#include<iostream>
#include<vector>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ���� �Ҽ� - ���Ʈ���� �˰���
/// n�� ���� �Ҽ� �Ǵܽ�, n�� ������� ���� n�� �������� �������� ��Ī
/// ���� sqrt(n) ������ �� ������ �˻縦 �����ϸ� �ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int T = 0; //�׽�Ʈ ���̽�
	long long n = 0;
	long long primeCnt = 0, num = 0; //�Ҽ� ���� primeNum, num = sqrt(n) + 1

	std::cin >> T;
	for ( int t = 0; t < T; t++ )
	{
		std::cin >> n;
		bool isPrimeNum = (n < 3) ? true : false;
		primeCnt = (n < 3) ? 2 : n;
		while ( !isPrimeNum )
		{
			num = sqrt(n) + 1;
			for ( int i = 2; i <= num; i++ )
			{
				if ( n % i == 0 )
				{
					break;
				}
				if ( i == num )
				{
					primeCnt = n;
					isPrimeNum = true;
				}
			}
			n++;
		}
		std::cout << primeCnt << "\n";
	}
	return 0;
}