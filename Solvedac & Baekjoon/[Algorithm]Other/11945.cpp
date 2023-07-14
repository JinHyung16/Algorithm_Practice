#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 뜨거운 붕어빵 - 문자열 알고리즘
/// string으로 입력받아 vector<string>에 넣는다.
/// 즉 N줄 입력받으면서 0번째 줄에 string으로 입력받은게 vector에 들어오면서 N번째 줄까지 각 string값이 들어가있게 된다.
/// 다 입력받고 for i to N 돌면서 reverse(vector[i].begin(), vector[i].end())를 진행하여 각 줄의 string값을 뒤집어서 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	int N = 0, M = 0; //N개의 줄과 M개의 값
	vector<string> result;
	string input;
	std::cin >> N >> M;
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> input;
		result.push_back(input);
	}

	for ( int i = 0; i < N; i++ )
	{
		reverse(result[i].begin(), result[i].end());
		std::cout << result[i] << "\n";
	}
	return 0;
}