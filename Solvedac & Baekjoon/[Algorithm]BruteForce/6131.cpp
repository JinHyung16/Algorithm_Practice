#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 ���� ������ - ���Ʈ���� �˰���
/// ������ �־��� ����ó��, �ִ� ������ 500���� 2�� for���� ���鼭
/// a*a = b*b + N�� �̿��Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0;
	std::cin >> N;

	int result = 0;
	for ( int i = 1; i <= 500; i++ )
	{
		for ( int j = i + 1; j <= 500; j++ )
		{
			if ( j * j == i * i + N )
			{
				result++;
			}
		}
	}

	std::cout << result << "\n";
	return 0;
}