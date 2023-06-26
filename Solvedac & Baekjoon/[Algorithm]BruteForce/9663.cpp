#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 N-Queen - 브루트포스 알고리즘
/// 
/// N-Queen은 백트래킹 알고리즘의 대표적인 문제다.
/// Queen의 특성상 체스판 한 행당 한개의 퀸만 존재 가능하기에 여기서부터 말을 시작한다. (서로 다른 퀸은 같은 행 또는 열에 위치할 수 없다)
/// 따라서 2차원 배열을 만드는 대신 1차원 배열로 해결하여 시간 복잡도를 단축한다.
/// 
/// column[0] = i는 0번째 열에 i번째 행의 위치해 있는 퀸이다. 이렇게 하여 i값이 서로 같이 않도록 배치하는 경우의 수를 모두 찾는다.
/// 퀸으 같은 라인에 있거나, 대각선에 있으면 안되므로 이를 체크한다.
/// 
/// 백트래킹은 일반적으로 재귀의 형태로 작성되는데,
/// 1) 재귀를 진행하는 동안 사용될 깊이 depth(또는 level)를 매개변수로 넣기
/// 2) 재귀가 종료되는 시점에서 수행할 내용
/// 3) 재귀가 진행중이면 가지치기(백트래킹)할 내용
/// 이 3가지를 작성해야 한다.
/// </summary>

using namespace std;

int N = 0; //N * N 크기의 체스판
int totalNQueen = 0;
vector<int> column(16, 0);

void NQueen(int c)
{
	if(c == N)
	{
		totalNQueen++;
	}
	else
	{
		for(int i = 0; i < N; i ++)
		{
			column[c] = i; //퀸 위치 정하기
			bool canSetQueen = true;
			for(int j = 0; j < c; j ++)
			{
				if(column[c] == column[j] || std::abs(column[c] - column[j]) == c - j)
				{
					canSetQueen = false;
					break;
				}
			}
			if ( canSetQueen )
			{
				NQueen(c + 1);
			}
		}
	}
}

int main(void)
{
	FastIO;

	std::cin >> N;
	NQueen(0);
	std::cout << totalNQueen << "\n";
	return 0;
}