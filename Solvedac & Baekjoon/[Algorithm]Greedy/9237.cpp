#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 이장님 초대 - 그리디 알고리즘
/// 초대 해야하는 마지막 날을 찾기위해, 입력으로 받은 나무를 내림차순 하고,
/// result값의 result와 배열[i] + day값 중 큰 수로 항상 받는다.
/// day는 i값이 증가할때마다 증가시킨다.
/// 그 후 마지막에 result를 출력하면 된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0; //묘목의 수 N
	std::cin >> N;
	vector<int> trees;
	for ( int i = 0; i < N; i++ )
	{
		int t = 0;
		std::cin >> t;
		trees.push_back(t);
	}

	int result = -1, day = 1;
	std::sort(trees.rbegin(), trees.rend());
	for ( int i = 0; i < trees.size(); i++ )
	{
		result = std::max(result, trees[i] + day);
		day++;
	}
	result++;

	std::cout << result << "\n";

	return 0;
}