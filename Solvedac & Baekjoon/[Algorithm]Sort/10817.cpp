#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 세 수 - 정렬 알고리즘
/// c++ STL에서 제공하는 sort는 O(nlogn)이므로 사용하여
/// 1번째 index를 출력하면 된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	vector<int> sortVec(3, 0);
	std::cin >> sortVec[0] >> sortVec[1] >> sortVec[2];

	std::sort(sortVec.begin(), sortVec.end());

	std::cout << sortVec[1] << "\n";
	return 0;
}

