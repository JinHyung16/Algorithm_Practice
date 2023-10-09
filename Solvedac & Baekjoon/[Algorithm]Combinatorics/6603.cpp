#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver2 로또 - 조합론 알고리즘
/// K와 S가 주어질 때 조합을 맞춰 항상 6개씩 뽑는게 독일 로또다.
/// 즉 이 문제는 잘 생각하면 DFS를 돌다가 depth가 6이면 로또 6개를 뽑았으니 출력 후 멈추면 된다.
/// </summary>

vector<int> S;
int lotto[6];

void DFS(int start, int depth, int k)
{
	if ( depth == 6 )
	{
		for ( int i = 0; i < 6; i++ )
			cout << lotto[i] << " ";
		cout << "\n";
		return;
	}

	for ( int i = start; i < k; i++ )
	{
		lotto[depth] = S[i];
		DFS(i + 1, depth + 1, k);
	}
}

int main(void)
{
	FastIO;

	int K = 0; //K개의 수
	while ( true )
	{
		cin >> K;
		if ( K == 0 )
			break;
		S.resize(K, 0);
		for ( int i = 0; i < K; i++ )
		{
			cin >> S[i];
		}
		DFS(0, 0, K);
		cout << "\n"; //여기에 넣어줘야 각 테스트 케이스별로 띄어쓰기로 구분됨
	}
	return 0;
}