#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 개수 세기 - 구현 알고리즘
/// numVec의 입력을 받아두고, for문을 돌면서 v랑 같을때면 카운팅한다.
/// </summary>


int main(void)
{
	FastIO;
	
	int N = 0, v = 0; //N개의 정수가 주어질 때, 정수 v 개수 찾기
	cin >> N;
	vector<int> numVec(N, 0);
	for ( int i = 0; i < N; i++ )
	{
		cin >> numVec[i];
	}
	cin >> v;

	int cnt = 0;
	for ( int i = 0; i < N; i++ )
	{
		if ( numVec[i] == v )
			cnt++;
	}

	cout << cnt << "\n";
	return 0;
}