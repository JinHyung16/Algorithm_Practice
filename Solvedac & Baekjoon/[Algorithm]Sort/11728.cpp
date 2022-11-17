#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver5 배열 합치기 - 정렬 알고리즘
/// 마지막에 최종적으로 sort해야 하니 c++의 sort는 O(nlogn)으로 이를 이용하자
/// 문제는 std::cin과 std::cout이 시간이 좀 걸려서 printf, scanf쓸거 아니면
/// 입 출력 속도 up 시키는게 필요하다
/// </summary>


int main(void)
{
	//입 출력 속도 up
	ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int aSize = 0, bSize = 0;
	std::cin >> aSize >> bSize;

	int totalSize = aSize + bSize;
	vector<int> totalVec(totalSize);

	for (int i = 0; i < totalSize; i++)
	{
		std::cin >> totalVec[i];
	}

	std::sort(totalVec.begin(), totalVec.end());

	for (int i = 0; i < totalVec.size(); i++)
	{
		std::cout << totalVec[i] << " ";
	}
	return 0;
}