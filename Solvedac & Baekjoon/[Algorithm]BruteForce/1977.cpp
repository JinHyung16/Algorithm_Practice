#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 완전제곱수 - 브루트포스 알고리즘
/// number 벡터에 for i = 1 to N 까지 i번째에 i*i 제곱수 값을 저장해둔다.
/// 그 후 N까지 for문을 돌면서 M이상 N이하의 number[i]번째 값을 찾아 sum과 minNum을 찾는다.
/// 이때 minNum은 N의 최대값이 10000이므로 10000으로 초기화 해놓는다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int M = 0, N = 0; //M이상 N이하의 자연수
	int sum = 0, minNum = 10000; //완전 제곱수 합, 완전 제곱수 중 최솟값
	std::cin >> M >> N;
	vector<int> number(N + 1);

	for ( int i = 1; i <= N; i++ )
	{
		number[i] = i * i;
	}

	for ( int i = 1; i <= N; i++ )
	{
		if ( M <= number[i] && number[i] <= N )
		{
			sum += number[i];
			minNum = std::min(minNum, number[i]);
		}
	}

	if ( sum == 0 )
	{
		std::cout << "-1" << "\n";
	}
	else
	{
		std::cout << sum << "\n" << minNum << "\n";
	}
	return 0;
}