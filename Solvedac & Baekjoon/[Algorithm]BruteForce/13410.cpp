#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 거꾸로 구구단 - 브루트포스 알고리즘
/// 구구단을 string으로 변환하여 길이만큼 뒤에서부터 for문을 돈다.
/// 그렇게 리버스 시킨 값을 stoi를 통해 int로 변환한 뒤 vector에 넣고
/// 마지막에 내림차순으로 sort시킨다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, K = 0;
	std::cin >> N >> K;

	vector<int> result;
	for ( int i = 1; i <= K; i++ )
	{
		string multi = std::to_string(N * i);
		string temp;
		for ( int j = multi.length() - 1; 0 <= j; j-- )
		{
			temp += multi[j];
		}
		int multi_int = std::stoi(temp);
		result.push_back(multi_int);
	}

	std::sort(result.rbegin(), result.rend());
	std::cout << result[0] << "\n";
	return 0;
}