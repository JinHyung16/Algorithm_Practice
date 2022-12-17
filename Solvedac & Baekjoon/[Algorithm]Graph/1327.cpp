#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<map>

/// <summary>
/// Gold5 소트 게임 - Graph 알고리즘
/// 오름차순 정렬을 하는게 최종 목표
/// 최소한의 소트로 만드는게 중요 -> 본인 앞보다 작고, 뒤보다 큰지 잘 보자
/// 처음엔 vecotr이용했으나, queue에 넣기 모호해서 string으로 변경
/// 배열 전체를 넣어서 계속 비교해보는 방향으로 변경
/// </summary>


using namespace std;

int n(0), k(0); //1부터 n까지 수, 뒤집어야하는 k개의 수
string graph;
map<string, bool> visited;

int BFS(string s)
{
	//오름차순으로 정렬된 배열 만들고 비교용으로 사용
	string ascendingOrder = s;
	std::sort(ascendingOrder.begin(), ascendingOrder.end());
	
	queue<pair<string, int>> q;
	q.push(make_pair(s, 0));
	visited[s] = true;
	
	while (!q.empty())
	{
		string now = q.front().first;
		int count = q.front().second;
		q.pop();

		if (now == ascendingOrder)
		{
			return count;
		}

		//바꿀수 있는 부분 다 찾기
		for (int i = 0; i <= n - k; i++)
		{
			//중간부분 빼서 바꾸기
			string temp = now.substr(i, k);
			
			//리버스 시키고
			reverse(temp.begin(), temp.end());

			//새로운 배열 만들기
			string next = now.substr(0, i);
			next += temp;

			//now의 끝까지 돌기
			next += now.substr(i + k);
			//중복 체크
			if (!visited.count(next))
			{
				q.push(make_pair(next, count + 1));
				visited[next] = true;
			}
		}
	}

	//오름 차순으로 만들 수 없으면 -1 출력
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		graph += c;
	}

	std::cout << BFS(graph) << std::endl;
	return 0;
}