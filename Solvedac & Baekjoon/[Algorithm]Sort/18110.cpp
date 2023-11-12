#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver4 solved.ac - 정렬 알고리즘
/// include<camth>를 통해 반올림 함수 round를 사용한다.
/// 그 외는 수학적인 계산으로 푼다.
/// 단! sort를 통해 오름차순이나 내림차순을 하여 제외 인원만큼 제외함을 잊지말자
/// </summary>

int main(void)
{
	FastIO;

	int n = 0; // 난이도 의견의 개수 n
	int input = 0; //입력

	cin >> n;
	if (n == 0)
	{
		cout << 0 << "\n";
		return 0;
	}

	vector<int> opinions;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		opinions.push_back(input);
	}

	int exceptNum = 0; //제외해야 하는 인원 수
	exceptNum = round(n * 0.15); //전체 제외 인원수는 30%지만 위 아래 따로 보면 각 0.15%씩이다.

	sort(opinions.begin(), opinions.end());
	double average = 0;
	for (int i = exceptNum; i < n - exceptNum; i++)
	{
		average += opinions[i];
	}

	average = round(average / (n - exceptNum * 2));
	cout << average << "\n";

	return 0;
}