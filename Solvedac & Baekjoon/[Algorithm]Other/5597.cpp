#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 과제 안 내신 분..? - 구현 알고리즘
/// 크기가 31인 배열을 만든다.
/// 왜냐면 학생수가 30이지만 index 출력은 1번부터 해야 하기 때문이다.
/// 학생 번호를 입력 받으면 해당 번호를 index로 하는 배열의 값을 1로 바꾼다.
/// for i=1 to 30을 통해 배열의 index의 값이 0일 때 i를 출력한다.
/// </summary>


int main(void)
{
	FastIO;

	vector<int> students(31, 0);

	int input = 0;
	for ( int i = 0; i < 28; i++ )
	{
		cin >> input;
		students[input] = 1;
	}

	for ( int i = 1; i <= 30; i++ )
	{
		if ( students[i] == 1 )
			continue;
		else
			cout << i << "\n";
	}
	return 0;
}