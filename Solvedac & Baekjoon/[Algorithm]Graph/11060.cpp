#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 점프 점프 - Graph 알고리즘
/// BFS를 이용한 풀이
/// DFS와 dp를 이용해서 최솟값을 dp에 저장해가면서 풀 수도 있을거 같다.
/// queue에는 현재 위치와 점프한 count 저장
/// </summary>

using namespace std;

vector<int> map(1001, 0); //n의 최대 크기가 1000이하
vector<bool> visited(1001, false); //방문 여부 체크하기
int minJumpCnt(0);

int BFS(int n)
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0] = true; //처음 지점은 항상 true

	while (!q.empty())
	{
		int curPos = q.front().first;
		int jumpCnt = q.front().second;
		q.pop();

		if (curPos == n - 1)
		{
			return jumpCnt;
		}

		int jump = map[curPos];
		for (int i = 0; i <= jump; i++)
		{
			int nextPos = curPos + i;
			if (!visited[nextPos])
			{
				visited[nextPos] = true;
				q.push({ nextPos, jumpCnt + 1 });
			}
		}
	}

	//가장 오른쪽으로 갈 수 없는 경우, -1을 return한다
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //미로의 size 1*n

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> map[i];
	}
	
	minJumpCnt = BFS(N);

	std::cout << minJumpCnt << std::endl;

	return 0;
}