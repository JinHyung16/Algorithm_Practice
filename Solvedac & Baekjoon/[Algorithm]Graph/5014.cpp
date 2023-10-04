#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 스타트링크 - Graph 알고리즘
/// 먼저 U와 D를 담아둘 배열을 선언한다.
/// 이때 D는 아래로 내려가는걸 의미하는 배열에선 왼쪽으로 가는 것으로 -1을 곱한다.
/// 그 후 BFS를 통해 U 또는 V 총 2번 for문을 돌아 움직이면서
/// moveCnt배열의 다음 지점까지 이동한 횟수를 이전 지점까지 이동한 횟수 + 1하여 저장한다.
/// </summary>

int moveDir[2];
vector<bool> visited;
vector<int> moveCnt;

void BFS(int start, int maxFloor)
{
	queue<int> q;
	visited[start] = true;
	q.push(start);

	while ( !q.empty() )
	{
		int cur = q.front();
		q.pop();

		for ( int i = 0; i < 2; i++ )
		{
			int next = cur + moveDir[i];
			if ( 0 < next && next <= maxFloor )
			{
				if ( !visited[next] )
				{
					visited[next] = true;
					q.push(next);
					moveCnt[next] = moveCnt[cur] + 1;
				}
			}
		}
	}
}

int main(void)
{
	FastIO;

	int F = 0, S = 0, G = 0, U = 0, D = 0; //F층 건물, 목표 위치 G층, U버튼(위), D버튼(아래), 현재 있는 곳 S층
	cin >> F >> S >> G >> U >> D;

	visited.resize(F + 1, false);
	moveCnt.resize(F + 1, 0);

	moveDir[0] = U;
	moveDir[1] = D * -1; //아래로 내려가니
	
	BFS(S, F);

	if ( visited[G] )
		cout << moveCnt[G] << "\n";
	else
		cout << "use the stairs" << "\n";
	return 0;
}