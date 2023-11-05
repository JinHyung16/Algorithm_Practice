#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 단어 길이 재기 - 구현 알고리즘
/// char로 입력받아 for문을 돌아 카운팅 할 수 있지만
/// 더 편하게 string으로 받아 .size()로 출력한다.
/// </summary>


int main(void)
{
	FastIO;

	string input;
	cin >> input;

	cout << input.size() << "\n";

	return 0;
}