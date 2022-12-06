#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver1 친구 - Graph 이론
/// 거리가 2이하면 친구로 카운팅하자, 이때 N로 대답한건 빼고 넣자
/// 본인과 본인이 친구인경우도 포함되어서 진행되기에 마지막 카운팅에서 -1 해주자 
/// dfs, bfs다 가능한 문제
/// </summary>

vector<int> friendTree[51];
vector<bool> visited(51, false);

//거리가 2이하면 친구로, 거리1일때 거리2일때 이렇게 depth가 2까지 돌자
void DFS(int depth, int start)
{
	visited[start] = true;
	if (depth == 2)
	{
		return;
	}
	for (int i = 0; i < friendTree[start].size(); i++)
	{
		DFS(depth + 1, friendTree[start][i]);
	}

}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		char answer;
		for (int j = 0; j < n; j++)
		{
			std::cin >> answer;
			if (answer == 'Y')
			{
				friendTree[i].push_back(j);
			}
		}
	}

	int friendCount = 0;
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		fill_n(visited.begin(), 51, false);

		DFS(0, i);
		for (int j = 0; j < n; j++)
		{
			if (visited[j] == true)
			{
				count++;
			}
		}
		//본인이랑 친구인것도 포함되어서 돌아가서 -1 해주자
		friendCount = std::max(friendCount, count - 1);
	}

	std::cout << friendCount << std::endl;

	
	return 0;
}