#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze2 정수의 개수 - DP 알고리즘
/// 정수의 개수는 콤마의 개수 +1개이다.
/// 따라서 전체 콤마의 개수를 파악한 뒤 +1 해서 출력한다.
/// </summary>

int main(void)
{
	FastIO;
	string input;
	int numCnt = 0;

	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ',')
		{
			numCnt++;
		}
	}

	cout << numCnt + 1 << "\n";
	return 0;
}