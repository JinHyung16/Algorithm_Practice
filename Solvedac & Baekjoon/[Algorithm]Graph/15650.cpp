#include<iostream>
#include<vector>


#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver3 N과 M (2) - Graph 알고리즘
/// 백트래킹을 이용한 풀이
/// DFS를 통해 M을 depth라 생각하여 실행한다.
/// M번 실행까지 for문을 통해 1부터 N까지 sequence vector의 m번째에 for문의 i값을 저장한다.
/// 그 후 DFS를 실행해 한 단계씩 증가시킨다.
/// </summary>


int N = 0, M = 0; //1 부터 N까지 자연수 중 중복없이 M개를 고르기
vector<int> sequence;

void DFS(int n, int m)
{
	if ( m == M )
	{
		for ( int i = 0; i < M; i++ )
		{
			cout << sequence[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		for ( int i = n; i <= N; i++ )
		{
			sequence[m] = i;
			DFS(i + 1, m + 1);
		}
	}
}

int main(void)
{
	FastIO;

	cin >> N >> M;
	sequence.resize(M + 1, 0);
	DFS(1, 0);
	return 0;
}