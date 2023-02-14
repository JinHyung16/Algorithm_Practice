#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 박 터뜨리기 - Greedy 알고리즘
/// 조건을 만족하면서 공을 넣으려면 두가지의 경우가 존재한다.
/// 1.연속적으로 넣는 경우 ex) N=6, K=3 -> 123 이렇게 넣는다.
/// 2.연속적이지 않는 경우 ex) N=7, K=3 -> 124 이렇게 넣는다.
/// (가장 많이 담긴 바구니의 공 개수 - 가장 적게 담긴 바구니의 공 개수)는
/// 1번의 경우 k-1, 2번의 경우 k다.
/// 1번의 경우 N%K가 0이고, 2번의 경우 N%K가 1인경우다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0), K(0); //공의 개수 N과 바구니의 수 K
	long long ballSum(0); //K개의 바구니의 공을 하나도 빠짐없이 연속적으로 채워놓을때 공의 개수 저장

	std::cin >> N >> K;
	for (int i = 1; i <= K; i++)
	{
		//1부터 바구니 개수까지의 합을 담아둔다.
		//이는 K개의 바구니의 공을 최소 1개씩 넣음과 동시에 연속적으로 담아두는걸 의미
		ballSum += i;
	}

	//내가 넣으려는 공의 개수와, 바구니에 공을 연속적으로 넣은 공의 개수를 빼서 음수인지 판별한다.
	N -= ballSum;

	if (N < 0)
	{
		//내가 넣으려는 공의 수가 ballSum보다 작다는건
		//제시된 조건 중 한개라도 만족 못하는걸로 판별
		std::cout << -1 << "\n";
		return 0;
	}

	if (N % K == 0)
	{
		std::cout << K - 1 << "\n";
	}
	else 
	{
		std::cout << K << "\n";
	}
	return 0;
}