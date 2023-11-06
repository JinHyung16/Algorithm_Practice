#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 문자열 - 구현 알고리즘
/// 문제를 해결할 때 문자열 길이에 따라 출력을 다르게한다.
/// 왜냐면 길이가 1보다 크면 0번째와 length()-1 번째 index를 출력하지만
/// 길이가 1이면 0번째가 첫 번째이자 마지막이 되므로 이를 2번 출력해야 하기 때문이다.
/// </summary>


int main(void)
{
	FastIO;
	
	int T = 0; //테스트 케이스 개수 T
	cin >> T;
	string input;
	while ( T-- )
	{
		cin >> input;
		if ( 1 < input.size() )
		{
			cout << input[0] << input[input.length() - 1] << "\n";
		}
		else
		{
			cout << input[0] << input[0] << "\n";
		}
		cin.clear();
	}
	return 0;
}