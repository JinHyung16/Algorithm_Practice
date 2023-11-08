#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 행렬 덧셈 - 구현 알고리즘
/// 두 행렬 A, B가 있을 때 덧셈은 그냥 같은 자리의 수를 더하면 된다.
/// 즉 A[i][j] + B[i][j]하면 된다.
/// </summary>


int main(void)
{
	FastIO;
	
	int N = 0, M = 0;
	cin >> N >> M;
	vector<vector<int>> matrixA(N, vector<int>(M, 0));
	vector<vector<int>> matrixB(N, vector<int>(M, 0));

	for ( int k = 0; k < 2; k++ )
	{
		for ( int i = 0; i < N; i++ )
		{
			for ( int j = 0; j < M; j++ )
			{
				if ( k == 0 )
				{
					cin >> matrixA[i][j];
				}
				else
				{
					cin >> matrixB[i][j];
				}
			}
		}
	}

	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < M; j++ )
		{
			matrixA[i][j] += matrixB[i][j];
		}
	}

	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < M; j++ )
		{
			cout << matrixA[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}