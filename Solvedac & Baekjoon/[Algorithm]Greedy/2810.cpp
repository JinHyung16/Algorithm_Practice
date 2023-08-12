#include<iostream>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 컵홀더 - Greedy 알고리즘
/// 좌석 정보를 입력받는다. 그 후 L은 커플석을 의미하므로 커플석의 개수를 센다.
/// 컵홀더 개수는 초기 N+1로 초기화 한 뒤, 커플석 개수에 따라 연산을 달리한다.
/// 커플석이 없다면 컴홀더 개수 = N
/// 커플석이 있다면 컵홀더 개수 = (N+1) - (couple/2)를 한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	int N = 0; //좌석의 수 N
	string input; //좌성 정보

	std::cin >> N;
	std::cin >> input;

	int result = N + 1;
	int couple = 0;

	for ( int i = 0; i < input.size(); i++ )
	{
		if ( input[i] == 'L' )
		{
			couple++;
		}
	}

	if ( couple == 0 )
	{
		result = N;
	}
	else
	{
		result -= (couple / 2);
	}

	std::cout << result << "\n";
	return 0;
}