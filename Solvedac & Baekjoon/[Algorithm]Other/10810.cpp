#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze3 공 넣기 - 구현 알고리즘
/// 문제에서 i,j,k가 주어질 때
/// i~j까지 k를 넣는다 했다.
/// 그러니 N + 1만큼 (왜냐면 바구니 시작이 1이니) 미리 배열을 만들고
/// 이 배열에 i, j, k가 입력으로 들어오면 바구니를 그때 그때 k로 채운다.
/// 이렇게 된다면 바구니에 값이 있을경우 자연스럽게 빼고 해당 k로 채우는것도 가능하다.
/// </summary>


int main(void)
{
	FastIO;
	
	int N = 0, M = 0; // 바구니 N개 M번 공을 넣음
	cin >> N >> M;
	vector<int> basket(N + 1, 0);
	for ( int i = 0; i < M; i++ )
	{
		int a = 0, b = 0, k = 0; // a번 바구니 ~ b번 바구니까지 k번호가 적혀져 있는 공을 넣음
		cin >> a >> b >> k;
		for ( int j = a; j <= b; j++ )
			basket[j] = k;
	}

	for ( int i = 1; i <= N; i++ )
	{
		cout << basket[i] << " ";
	}
	cout << "\n";

	return 0;
}