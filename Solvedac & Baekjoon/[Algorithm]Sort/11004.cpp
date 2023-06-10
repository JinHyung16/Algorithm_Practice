#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 K번째 수 - 정렬 알고리즘
/// vector에 수를 받아 둔 뒤, sort하여 k번째 index를 출력한다.
/// 이때 vector의 index는 실제 수보다 1 작으므로 k-1해서 넣는다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0), K(0); //N개의 수, K번째 수
	std::cin >> N >> K;

	vector<int> numVec(N, 0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> numVec[i];
	}

	std::sort(numVec.begin(), numVec.end());
	std::cout << numVec[K - 1] << "\n";
	return 0;
}