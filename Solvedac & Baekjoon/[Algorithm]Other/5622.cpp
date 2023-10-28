#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze2 다이얼 - 구현 알고리즘
/// 예전에 문제를 풀었을 땐, 각 알파벳을 받아 숫자를 출력하는 형식이였다.
/// 이를 조금 더 간단하게 배열로 바꿔본다.
/// 대문자 A를 숫자 0으로 하려면 아스크 코드로 65번째 이므로 A[i] - 65를한다.
/// </summary>


int alpha[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };

int main(void)
{
	FastIO;
	
	string input;
	int time = 0;

	cin >> input;
	for ( int i = 0; i < input.length(); i++ )
	{
		time += alpha[input[i] - 65];
	}

	cout << time << "\n";
	return 0;
}