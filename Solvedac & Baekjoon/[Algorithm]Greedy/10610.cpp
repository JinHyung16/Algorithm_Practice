#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 30 - Greedy 알고리즘
/// 0으로 시작하지 않으므로, 받은 수를 string으로 받고 내림차순 정렬한다.
/// 30의 배수면 마지막 수는 무조건 0이다.
/// long long에 넣어서 해당 값을 3으로 나눠 나머지가 0이면 출력 아니면 -1 출력한다.
/// 왜 3으로 나누냐? string 30을 char로 쪼개어 더하면 3이므로
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string N;
	std::cin >> N;
	std::sort(N.begin(), N.end(), std::greater<>());
	if (N[N.length() - 1] != '0')
	{
		//마지막 수가 0이 아니라면
		std::cout << -1 << "\n";
		return 0;
	}

	long long result(0);
	for (char c : N)
	{
		//string의 앞에서부터 1개의 char씩 읽어서 int로 변환해 더해넣는다
		result += (c - '0');
	}

	if (result % 3 == 0)
	{
		std::cout << N << "\n";
	}
	else
	{
		std::cout << -1 << "\n";
	}
	return 0;
}