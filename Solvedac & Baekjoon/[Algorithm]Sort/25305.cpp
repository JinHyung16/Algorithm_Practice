#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 커트라인 - 정렬 알고리즘
/// vector에 응시자의 점수를 입력받아 넣는다.
/// 내림차순을 하기 위해서 sort에 내림차순 비교를 위해 만든 DescendingOrder 함수를 넣어 내림차순 한다.
/// 그 후 k-1 번째 index를 출력한다. 왜냐면 vector의 index는 0부터 시작이므로 1 작아야하니깐
/// </summary>

using namespace std;

bool DescendingOrder(int a, int b)
{
	return b < a;
}

int main(void)
{
	FastIO;
	
	int N(0), k(0); //응시자의 수 N, 상을 받는 사람의 수 k
	int x(0); //각 학생의 점수 x
	
	vector<int> awardScores;
	std::cin >> N >> k;
	for (int i = 0; i < N; i++)
	{
		std::cin >> x;
		awardScores.push_back(x);
	}
	std::sort(awardScores.begin(), awardScores.end(), DescendingOrder);
	std::cout << awardScores[k - 1] << "\n";
	return 0;
}
