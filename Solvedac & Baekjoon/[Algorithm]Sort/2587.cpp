#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 대표값2 - 정렬 알고리즘
/// 평균 = 전체 합 / vector.size()를 진행한다.
/// 중앙값의 경우 오름차순 정렬 후 vector의 3번째 index 즉 vec[2]를 호출하면 된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	vector<int> numVec(5, 0);
	int averageNum = 0;
	for (int i = 0; i < numVec.size(); i++)
	{
		std::cin >> numVec[i];
		averageNum += numVec[i];
	}

	averageNum /= numVec.size();
	std::sort(numVec.begin(), numVec.end());

	std::cout << averageNum << "\n" << numVec[2] << "\n";
	return 0;
}
