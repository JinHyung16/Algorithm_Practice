#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 팀 나누기 - 구현 알고리즘
/// 문제에서 이미 정렬된 채로 입력이 들어오니 정렬은 필요없다.
/// (가장 작은 값 + 가장 큰 값) vs (두번째 작은 값 + 두번째 큰 값)
/// 이렇게 차이를 비교한다.
/// </summary>


int main(void)
{
	FastIO;
	
	vector<int> people(4, 0);
	cin >> people[0] >> people[1] >> people[2] >> people[3];

	int result = abs((people[0] + people[3]) - (people[1] + people[2]));
	cout << result << "\n";

	return 0;
}