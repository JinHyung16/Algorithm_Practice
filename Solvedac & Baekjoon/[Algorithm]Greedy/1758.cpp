#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 알바생 강호 - Greedy 알고리즘
/// 받을 수 있는 팁의 최댓값은 가장 많은 팁을 주는 사람을 먼저주면 된다.
/// (받은 등수 - 1)이므로 1등은 0, 2등은 1, 3등은 2 이런식으로 결과가 나온다.
/// 따라서 이 결과를 배열의 index로 0, 1, 2 ... 사용하면 된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //서 있는 사람의 수 N
	vector<int> tipVec(100001, 0); //tip들 저장할 배열
	long long tipSum(0); //받을 수 있는 최대 tip값

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> tipVec[i];
	}
	
	//tip이 가장 큰 순서대로 정렬하기
	std::sort(tipVec.begin(), tipVec.end(), std::greater<>());

	for (int i = 0; i < N; i++)
	{
		if (0 < tipVec[i] - i)
		{
			//i는 (등수-1)을 의미, 등수별로 tip주는데 양수면
			tipSum += (tipVec[i] - i);
		}
	}

	std::cout << tipSum << "\n";
	
	return 0;
}