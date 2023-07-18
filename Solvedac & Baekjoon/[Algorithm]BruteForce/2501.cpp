#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 ��� ���ϱ� - ���Ʈ���� �˰���
/// ����� ������ ���� temp ������ �����Ѵ�.
/// ����� vector�� ���ʴ�� �����Ѵ�.
/// vector�� ����� �ش��ϴ� divisor index�� i���� �����Ѵ�.
/// �� �� K���� ��� ������ ũ�ų� ������ ���Ϳ��� ���� ����ϰ�
/// �ƴϸ� 0�� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0, K = 0; //N�� ����� �� K��°�� ���� ��
	std::cin >> N >> K;
	
	int divisor = 0;
	int temp = 0;
	vector<int> divisorVec(10000, 0);
	for ( int i = 1; i <= N; i++ )
	{
		if ( (N % i) == 0 )
		{
			divisorVec[divisor] = i;
			divisor++;
			temp++;
		}
	}

	if ( K <= temp )
	{
		std::cout << divisorVec[K - 1] << "\n";
	}
	else
	{
		std::cout << 0 << "\n";
	}
	return 0;
}