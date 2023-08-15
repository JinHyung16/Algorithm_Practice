#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 점수 집계 - 정렬 알고리즘
/// sort하여 vector의 index 1번과 3번을 비교한다. (왜냐면 0번부터 시작이니)
/// 그 후 4이상이면 KIN 출력후 continue로 빠르게 끝내고 다음 입력을 받는다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int T = 0; //테스트 케이스 개수
	std::cin >> T;

	while ( T-- )
	{
		vector<int> scores;
		for ( int i = 0; i < 5; i++ )
		{
			int input;
			std::cin >> input;
			scores.push_back(input);
		}

		std::sort(scores.begin(), scores.end());
		if ( 4 <= scores[3] - scores[1] )
		{
			std::cout << "KIN" << "\n";
			continue;
		}
		std::cout << scores[1] + scores[2] + scores[3] << "\n";
	}
	return 0;
}