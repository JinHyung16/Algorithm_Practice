#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 �� �����ϱ� - ���Ʈ���� �˰���
/// 3�� for���� ���� A, B, C�� ���� ���� ������Ű�鼭 ã�´�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int A = 0, B = 0, C = 0; //���� ������ ��Ÿ���� ���δٸ� �� �ڿ��� A, B, C
	int N = 0; //��ü �л� �� N
	std::cin >> A >> B >> C >> N;
	for ( int i = 0; i <= N; i++ )
	{
		int a = A * i;
		for ( int j = 0; j <= N; j++ )
		{
			int b = B * j;
			for ( int k = 0; k <= N; k++ )
			{
				int c = C * k;
				if ( a + b + c == N )
				{
					std::cout << "1" << "\n";
					return 0;
				}
				
			}
		}
	}

	std::cout << "0" << "\n";
	return 0;
}