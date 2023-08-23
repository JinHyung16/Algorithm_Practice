#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ���̴� ���� ���� - ������ �˰���
/// �ִ� ������� ���� 1�̸� ������ ������Ű��
/// �̰� vector�� �ִ´�.
/// �̸� ���س���, N�� �Է¹޾� �ٷιٷ� ����Ѵ�.
/// </summary>

using namespace std;

int GCD(int a, int b)
{
	int t = 0;
	while ( b )
	{
		t = a % b;
		a = b;
		b = t;
	}

	return a;
}

int main(void)
{
	FastIO;
	
	int C = 0; //�׽�Ʈ ���̽��� ���� C
	std::cin >> C;
	vector<int> prefix(1001, 0);
	prefix[0] = 0, prefix[1] = 3;

	for ( int i = 2; i <= 1000; i++ )
	{
		int cnt = 0;
		for ( int j = 1; j < i; j++ )
		{
			if ( GCD(i, j) == 1 )
			{
				cnt++;
			}
		}
		prefix[i] = prefix[i - 1] + 2 * cnt;
	}

	for ( int i = 0; i < C; i++ )
	{
		int N = 0; 
		std::cin >> N;
		std::cout << prefix[N] << "\n";
	}
	return 0;
}