#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 한동이는 공부가 하기 싫어! - Graph 알고리즘
/// 하나 이상의 정답이 있는 경우 번호가 작은 선배를 출력해야 하므로, 번호가 작은 노드부터 탐색을 시도한다.
/// </summary>

using namespace std;

int N = 0; //선배들의 번호 N
vector<int> person(1001, 0);
vector<bool>visited(1001, false);

void ResetVisit()
{
	for ( int i = 0; i < visited.size(); i++ )
	{
		if ( visited[i] )
		{
			visited[i] = false;
		}
	}
}

int main(void)
{
	FastIO;

	std::cin >> N;

	for ( int i = 0; i < N; i++ )
	{
		int input = 0;
		std::cin >> input;
		input -= 1;
		person[i] = input;
	}

	int meet = 0;
	int minPerson = 0;
	for ( int i = 0; i < N; i++ )
	{
		ResetVisit();
		int cur = i;
		int cnt = 0;
		while ( !visited[cur] )
		{
			visited[cur] = true;
			cur = person[cur];
			cnt += 1;
		}

		if ( meet < cnt )
		{
			meet = cnt;
			minPerson = i;
		}
	}

	std::cout << minPerson + 1 << "\n";

	return 0;
}