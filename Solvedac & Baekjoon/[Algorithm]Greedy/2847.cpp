#include<iostream>
#include<algorithm>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 게임을 만든 동준이 - 그리디 알고리즘
/// 값을 다 입력 받고 뒤에서부터 for문을 돈다.
/// 만약 현재 값 보다 이전 값이 더 크면 1씩 계속 빼주면서 몇 번 뺐는지 카운팅한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0; //레벨의 수 N
	std::cin >> N;
	vector<int> inputLevel(N, 0);

	for ( int i = 0; i < N; i++ )
	{
		std::cin >> inputLevel[i];
	}

	int cnt = 0;
	for ( int i = N - 1; 0 < i; i-- )
	{
		while ( inputLevel[i] <= inputLevel[i - 1] )
		{
			inputLevel[i - 1] -= 1;
			cnt++;
		}
	}

	std::cout << cnt << "\n";
	return 0;
}	