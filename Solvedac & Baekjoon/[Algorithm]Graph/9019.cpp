#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 DSLR - 그래프 알고리즘
/// D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
/// S: S 는 n에서 1 을 뺀 결과 n - 1을 레지스터에 저장한다.n이 0 이라면 9999 가 대신 레지스터에 저장된다.
/// L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다.이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
/// R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다.이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
/// 
/// BFS를 이용해 start에서 각 DSLR의 연산을 진행하면서 pair의 두번째 값으로 해당 연산이 진행됐다면 각 맞는 연산 알파벳 "D, S, L, R"중 하나를 넣는다.
/// 이렇게 반복하면서 start == end가 되면 현재 저장된 문자열값을 반환한다.
/// </summary>

using namespace std;

vector<bool> visited(10001, false);

void ResetVisited()
{
	for (int i = 0; i < visited.size(); i++)
	{
		visited[i] = false;
	}
}

string BFS(int start, int end)
{
	queue<pair<int, string>> q;
	q.push(make_pair(start, ""));
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		string commend = q.front().second;
		q.pop();

		if (cur == end)
		{
			return commend;
		}

		int next = cur * 2;
		if (9999 < next)
		{
			next %= 10000;
		}
		if (!visited[next])
		{
			visited[next] = true;
			q.push({ next, commend + "D" });
		}

		next = cur - 1;
		if (next < 0)
		{
			next = 9999;
		}
		if (!visited[next])
		{
			visited[next] = true;
			q.push({ next, commend + "S" });
		}

		next = (cur % 1000) * 10 + (cur / 1000);
		if (!visited[next])
		{
			visited[next] = true;
			q.push({ next, commend + "L" });
		}

		next = (cur % 10) * 1000 + (cur / 10);
		if (!visited[next])
		{
			visited[next] = true;
			q.push({ next, commend + "R" });
		}
	}
}

int main(void)
{
	FastIO;
	
	int T(0); //테스트 케이스의 개수 T
	int A(0), B(0); //두 개의 정수 A, B
	
	std::cin >> T;
	while (T--)
	{
		std::cin >> A >> B;
		ResetVisited();
		string result = BFS(A, B);
		std::cout << result << "\n";
	}
	return 0;
}