#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 세수정렬 - 정렬 알고리즘
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	vector<int> numVec(3, 0);
	for (int i = 0; i < numVec.size(); i++)
	{
		std::cin >> numVec[i];
	}

	std::sort(numVec.begin(), numVec.end());
	
	for (int i = 0; i < numVec.size(); i++)
	{
		std::cout << numVec[i] << " ";
	}
	std::cout << "\n";
	return 0;
}
