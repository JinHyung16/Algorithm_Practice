#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 이항 계수 1 - 수학 알고리즘
/// 이항 계수 공식은 N!/((N-K)! * K!)이다.
/// 이때 팩토리얼 구하는 부분만 구현하면 된다.
/// 이때, vector를 이용해 vec[i]는 i번까지 팩토리얼 계산한 값을 저장하고 있는다.
/// </summary>

using namespace std;

int Factorial(int n)
{
	vector<int> vec(n + 1, 0);
	vec[0] = 1;
	
	for (int i = 1; i <= n; i++)
	{
		vec[i] = i * vec[i - 1];
	}
	
	return vec[n];
}

int main(void)
{
	FastIO;
	
	int N(0), K(0); //자연수 N과 정수 K
	std::cin >> N >> K;

	int result = Factorial(N) / (Factorial((N - K)) * Factorial(K));

	std::cout << result << "\n";
	return 0;
}