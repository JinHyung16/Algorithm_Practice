#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 모음의 개수 - 문자열 알고리즘
/// if 조건에 ||를 통해 한번에 해결한다.
/// </summary>


int main(void)
{
	FastIO;

	string input;
	cin >> input;

	int result = 0;

	for ( int i = 0; i < input.size(); i++ )
	{
		if ( input[i] == 'a' ||
			input[i] == 'e' ||
			input[i] == 'i' ||
			input[i] == 'o' ||
			input[i] == 'u' )
			result++;
	}

	cout << result << "\n";
	return 0;
}