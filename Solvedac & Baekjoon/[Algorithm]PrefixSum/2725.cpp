#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 보이는 점의 개수 - 누적합 알고리즘
/// 최대 공약수를 구해 1이면 개수를 증가시키고
/// 이걸 vector의 넣는다.
/// 미리 구해놓고, N을 입력받아 바로바로 출력한다.
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
	
	int C = 0; //테스트 케이스의 개수 C
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