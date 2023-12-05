#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver5 수들의 합 - 수학 알고리즘
/// 투 포인터 문제다.
/// 즉 while문을 돌건데
/// start와 end 변수가 있다.
/// 둘 다 1에서 시작하여 start + end를 주어진 N과 비교한다.
/// start + end = sum으로 치환
/// sum < N -> end를 1씩 늘리고 sum += end
/// sum == N -> 카운팅 시작, sum += end;
/// sum > N -> sum -= start 하고 start를 1씩 늘린다
/// 
/// ex) N = 5일 때
/// start = 1, end = 1 -> 1 + 1 < N
/// start = 1, end = 2 -> 1 + 2 < N
/// start = 1, end = 3 -> 1 + 2 + 3 > N
/// </summary>

int main(void)
{
	FastIO;
	int N = 0;
	int start = 1, end = 1, sum = 1, cnt = 1;

	cin >> N;
	while(end != N)
	{
		if (N == sum)
		{
			cnt++;
			end++;
			sum += end;
		}
		else if (sum < N)
		{
			end++;
			sum += end;
		}
		else
		{
			sum -= start;
			start++;
		}
	}

	cout << cnt << "\n";
	return 0;
}