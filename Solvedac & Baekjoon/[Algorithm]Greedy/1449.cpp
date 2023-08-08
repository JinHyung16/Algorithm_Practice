#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 수리공 항승 - Greedy 알고리즘
/// 1) 물이 새는 곳을 오름차순 한다.
/// 2) 테이프의 길이 <= 시작점 부터 다른 누수 지점까지의 거리면
///		필요한 테이프 개수 + 1하고 시작 위치를 재조정한다.
/// 2)의 과정을 반복한 뒤, 마지막 테이프의 개수는 세어지지 않으므로 +1한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, L = 0; //물이 새는 곳의 개수 N, 테이프의 길이 L
	int needTapeCnt = 0;
	std::cin >> N >> L;
	vector<int> greedy(N, 0);
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> greedy[i];
	}

	std::sort(greedy.begin(), greedy.end());
	int start = greedy[0];
	for ( int i = 1; i < N; i++ )
	{
		if ( L <= greedy[i] - start )
		{
			needTapeCnt++;
			start = greedy[i];
		}
	}
	needTapeCnt++;

	std::cout << needTapeCnt << "\n";
	return 0;
}