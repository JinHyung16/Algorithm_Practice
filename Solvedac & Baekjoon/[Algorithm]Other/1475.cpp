#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver5 방 번호 - 구현 알고리즘
/// 이 문제에 핵심은 6과 9를 뒤집어 사용 가능하기에
/// 이를 잘 파악해야 한다.
/// 만약 6이 2번 9가 1번 사용됐다면
/// 실제로는 카드는 (numCard[6] + numCard[9] + 1) / 2)
/// (2 + 1 + 1) / 2를 해서 2세트 사용 됐음을 구한다.
/// </summary>

int main(void)
{
	FastIO;
	
	int N = 0; // 방 번호 N
	int numCard[10] = { 0 };
	cin >> N;

	while (true)
	{
		numCard[N % 10]++;
		if (N / 10 == 0) 
			break;
		N /= 10;
	}

	int temp = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i != 9 && i != 6)
			temp = max(temp, numCard[i]);
	}

	int result = max(temp, (numCard[6] + numCard[9] + 1) / 2);
	cout << result << "\n";
	return 0;
}