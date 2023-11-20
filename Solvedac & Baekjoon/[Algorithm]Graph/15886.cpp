#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver3 내 선물을 받아줘 2 - Graph 알고리즘
/// 문제에서 E와 W에 따라 이동이 반대다.
/// 그렇다는건 E에서 W로 바뀌는 곳에 선물을 놓으면
/// 무조건 선물을 받는다는 뜻이다.
/// </summary>

vector<int> map;
string sInput;

void DFS(int start)
{
	if ( map[start] == 1 )
		return;
	map[start] = 1;

	if ( sInput[start] == 'E' )
		DFS(start + 1);
	else
		DFS(start - 1);
}

int main(void)
{
	FastIO;

	int N = 0; // 골목길의 길이 N
	cin >> N;
	cin >> sInput;
	map.resize(N, 0);
	int answer = 0;
	for ( int i = 0; i < sInput.length(); i++ )
	{
		if ( map[i] != 1 && sInput[i] == 'E' )
		{
			DFS(i);
			answer++;
		}
	}

	cout << answer << "\n";
	return 0;
}