#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 구간 합 구하기4 - 누적합 알고리즘
/// 구간 i~j의 누적합을 구해야한다.
/// 즉 이말은 미리 입력받을때 i번째의 i까지의 누적합을 저장해둔 다음
/// 구간 i와 j를 입력받으면 vec[j] - vec[i]를 진행하면 j까지의 구간합에서 i까지 구간합을 뺀 값으로 이는 i~j까지의 구간합이다
/// 이때 범위에서 주의해야 하는데, 구간 i에서 j면 i와 j를 포함하는 구간을 의미하므로
/// 결국 vec[j]는 j를 포함한 구간까지의 합이고 vec[i]는 i를 포함한 구간까지의 합이므로 둘을 뺄때는 vec[j] - vec[i-1]을해서 i의 이전 구간까지의 합을 빼야한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0), M(0); //수의 개수 N, 합을 구해야 하는 횟수 M
	int I(0), J(0); //합을 구해야 하는 구간 I, J
	
	std::cin >> N >> M;
	vector<int> numVec(N + 1, 0);
	for (int n = 1; n <= N; n++)
	{
		std::cin >> numVec[n];
		numVec[n] += numVec[n - 1];
	}

	for (int m = 0; m < M; m++)
	{
		std::cin >> I >> J;
		std::cout << numVec[J] - numVec[I - 1] << "\n";
	}
	return 0;
}