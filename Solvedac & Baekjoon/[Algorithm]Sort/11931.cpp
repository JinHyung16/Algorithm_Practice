#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver5 수 정렬하기 4 - 정렬 알고리즘
/// </summary>

int main(void)
{
	FastIO;

	int N = 0; // N개의 수
	cin >> N;

	vector<int> vec(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}
	sort(vec.rbegin(), vec.rend());
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "\n";
	}
	return 0;
}