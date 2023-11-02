#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 코딩은 체육과목 입니다 - 구현 알고리즘
/// </summary>

int main(void)
{
	FastIO;

	int N = 0; //N바이트 정수까지 저장
	string basic = "long int";
	string addByte = "long";
	cin >> N;

	int longCnt = (N / 4);

	for (int i = 0; i < longCnt - 1; i++)
	{
		cout << addByte << " ";
	}
	cout << basic << "\n";
	return 0;
}