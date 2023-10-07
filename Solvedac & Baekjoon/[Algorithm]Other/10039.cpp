#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 평균 점수 - 수학 알고리즘
/// 문제에서 학생들의 점수를 저장해야 하는 경우는 없기 때문에
/// 입력 받을 때 40점 미만인 것만 체크하여 40으로 바꾸고 변수 하나에 다 더해놓는다.
/// 그 후 5명의 입력을 받으니 5로 나누어 출력한다.
/// </summary>

int main(void)
{
	FastIO;
	
	int scoresSum = 0;
	int score = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> score;
		if (score < 40)
			score = 40;
		scoresSum += score;
	}
	
	cout << scoresSum / 5 << "\n";
	return 0;
}