#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 ������ ȣ��� - ���Ʈ���� �˰���
/// 2�� for���� ���鼭 1���� n���� �� ã�ƺ���.
/// ���� �������� ���ٸ� ������� �ǹ̷� result���� ������Ų��.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int T = 0; //�׽�Ʈ ���̽��� ���� T
	std::cin >> T;
	int a = 0, b = 0;
	while ( T-- )
	{
		int n = 0, m = 0;	
		int result = 0;
		std::cin >> n >> m;
		for ( a = 1; a < n; a++ )
		{
			for ( b = a + 1; b < n; b++ )
			{
				if ( !((a * a + b * b + m) % (a * b)) )
				{
					result++;
				}
			}
		}
		std::cout << result << "\n";
	}
	return 0;
}