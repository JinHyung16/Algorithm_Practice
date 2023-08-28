#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 점수 계산 - 정렬 알고리즘
/// 점수를 입력받고, 이때 해당 입력 순서도 vector<pair<int,int>>를 통해 입력받고
/// 점수가 큰 순부터 내림차순 한다.
/// 그 후 5개의 합을 구하고, 해당 문제 번호를 다시 vector의 옮긴다.
/// 옮긴 vector를 오름차순하여 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int sum = 0;
	vector<pair<int, int>> scores(8);
	vector<int> nums;
	for ( int i = 0; i < 8; i++ )
	{
		std::cin >> scores[i].first;
		scores[i].second = i + 1;
	}
	std::sort(scores.begin(), scores.end(), std::greater<pair<int, int>>());

	for ( int i = 0; i < 5; i++ )
	{
		sum += scores[i].first;
		nums.push_back(scores[i].second);
	}

	std::sort(nums.begin(), nums.end());

	std::cout << sum << "\n";
	for ( int i = 0; i < 5; i++ )
	{
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
	return 0;
}