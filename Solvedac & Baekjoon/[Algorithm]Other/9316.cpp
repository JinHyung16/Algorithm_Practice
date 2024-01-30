#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 Hello Judge - 구현 알고리즘
/// 마지막 숫자만 for문에 index를 출력하면 된다.
/// </summary>


int main(void)
{
	FastIO;
	
	int N = 0;
	cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		cout << "Hello World, Judge " << (i + 1) << "!" << "\n";
	}

	return 0;
}