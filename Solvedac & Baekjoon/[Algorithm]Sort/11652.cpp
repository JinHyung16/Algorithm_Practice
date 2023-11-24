#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver4 카드 - Sort 알고리즘
/// 우선 card 배열에 입력 값을 담고 오름차순한다.
/// 그 후 중복된 횟수를 저장하는 변수와 지금까지 가장 중복 많이 된 횟수를 저장하는 변수
/// 각각 dupliCnt, maxDupliCnt를 선언한다.
/// 초기 answer = card[0]에서 시작하고 for i = 1 to i < N 까지 돌면서
/// 이전과 현재 카드가 같다면 중복 카운팅을 늘리고 가장 중복 많이된 변수보다 현재 중복 카운트가 크다면
/// answer값을 바꾼다.
/// </summary>

int main(void)
{
	FastIO;

	int N = 0; // 숫자 카드 N장
	cin >> N;

	vector<long long> card(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> card[i];
	}
	sort(card.begin(), card.end());

	long long answer = card[0];
	int dupliCnt = 0, maxDupilCnt = 0;
	for (int i = 1; i < N; i++)
	{
		if (card[i] == card[i - 1])
		{
			dupliCnt++; // 중복 횟수 증가
			if (maxDupilCnt < dupliCnt) // 가장 많은 중복 횟수보다 크다면
			{
				maxDupilCnt = dupliCnt; // 가장 많은 중복 횟수를 바꾸고
				answer = card[i]; // 해당 값을 answer로 교체
			}
		}
		else
		{
			dupliCnt = 0; // 중복이 안됐다면 0으로 초기화해서 카운팅 다시 시작
		}
	}

	cout << answer;
	return 0;
}