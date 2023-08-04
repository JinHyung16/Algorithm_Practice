#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 5와 6의 차이 - 그리디 알고리즘
/// string으로 입력받고 5인 부분은 6으로 바꿔 한번 연산하고,
/// 6인 부분은 5로 바꿔 연산한다.
/// 그 후 이 두 연산값을 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string a, b;
	std::cin >> a >> b;

	for ( int i = 0; i < a.length(); i++ )
	{
		if ( a[i] == '6' )
		{
			a[i] = '5';
		}
	}
	for ( int i = 0; i < b.length(); i++ )
	{
		if ( b[i] == '6' )
		{
			b[i] = '5';
		}
	}
	int fiveSum = std::stoi(a) + std::stoi(b);
	for ( int i = 0; i < a.length(); i++ )
	{
		if ( a[i] == '5' )
		{
			a[i] = '6';
		}
	}
	for ( int i = 0; i < b.length(); i++ )
	{
		if ( b[i] == '5' )
		{
			b[i] = '6';
		}
	}
	int sixSum = std::stoi(a) + std::stoi(b);

	std::cout << fiveSum << " " << sixSum << "\n";
	return 0;
}