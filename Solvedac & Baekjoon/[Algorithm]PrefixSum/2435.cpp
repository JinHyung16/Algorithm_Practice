#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 기상청 인턴 신현수 - 누적합 알고리즘
/// 누적합이란 1일부터 K일까지 있을때, 이전 값과 현재값을 더해 누적해놓는 것을 말한다.
/// ex) 1일부터 5일까지 누적합을 구해놓고, 3~5일 사이의 누적값을 출력하고 싶으면
/// 5일까지의 누적합 - 2일까지의 누적합을 통해 구한다.
/// 왜냐하면 1~3일까지 누적합과 1~5일까지의 누적합중 1~2일까지의 누적합이 중복되기 때문이다.
/// 이런식으로 문제를 접근한다.
/// temperature vector에 미리 누적합을 저장해둔다.
/// K일부터 N일까지 for문을 돌면서, i일 누적합에 i-k일의 누적합을 빼서 max값보다 크면 이를 교체한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0, K = 0; //온도를 측정한 전체 날짜 N, 합을 구하기 위한 연속적인 날짜의 수 K
	std::cin >> N >> K;

	vector<int> temperature(N + 1, 0);

	for ( int i = 1; i <= N; i++ )
	{
		int input = 0;
		std::cin >> input;
		temperature[i] = input + temperature[i - 1];
	}

	int maxResult = -987654321;
	for ( int i = K; i <= N; i++ )
	{
		int temp = temperature[i] - temperature[i - K];
		if ( maxResult < temp )
		{
			maxResult = temp;
		}
	}

	std::cout << maxResult << "\n";
	return 0;
}