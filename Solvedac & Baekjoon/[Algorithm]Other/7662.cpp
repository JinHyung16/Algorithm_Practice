#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 이중 우선순위 큐 - 자료 구조 알고리즘
/// 우선 순위 큐를 이용해, 가장 큰 값과 가장 작은 값 순서대로 따로 저장해둔다.
/// 들어온 char가 I라면 pq에 삽입을, D라면 pq에서 해당 숫자를 뺀다.
/// 
/// maxPQ와 minPQ마다 유효하지 않는 숫자를 삭제하는 이유는, 현재 두개의 우선순위 큐를 사용하다보니
/// 반대쪽에서 이미 지웠을수도 있는 수를 찾아 맞추기 위함이다.
/// 
/// while문 조건에서 !.empty()후 if문에서 !visited하면 오류가 난다.
/// 이유는 이중 조건으로 한번에 검사해서 안들어가거나 들어간 뒤 검사하면서 돌거나의 차이같다.
/// 
/// 또한 pair의 정렬은 first 즉 n을 기준으로 정렬되니깐 top().first인지 second인지 잘 파악하자
/// </summary>

using namespace std;

vector<bool> visited(1000001, false);

int main(void)
{
	FastIO;

	int T(0); //T개의 테스트
	std::cin >> T;

	while(T--)
	{
		int N(0); //주어진 문자와 숫자 개수
		std::cin >> N;
		priority_queue<pair<int, int>> maxPQ;
		priority_queue<pair<int, int>, vector<pair<int,int>>, std::greater<pair<int, int>>> minPQ; //pair의 first를 기준으로 정렬된다.

		for (int i = 0; i < N; i++)
		{
			char c;
			int n;
			std::cin >> c >> n;

			if (c == 'I')
			{
				maxPQ.push({ n, i });
				minPQ.push({ n, i });
				visited[i] = true;
			}
			else
			{
				if (n == 1)
				{
					//유효하지 않은 값들은 다 삭제
					while (!maxPQ.empty() && !visited[maxPQ.top().second])
					{
						maxPQ.pop();
					}

					if (!maxPQ.empty())
					{
						visited[maxPQ.top().second] = false;
						maxPQ.pop();
					}
				}
				else
				{
					while (!minPQ.empty() && !visited[minPQ.top().second])
					{
						minPQ.pop();
					}

					if (!minPQ.empty())
					{
						visited[minPQ.top().second] = false;
						minPQ.pop();
					}
				}
			}
		}

		while (!maxPQ.empty() && !visited[maxPQ.top().second])
		{
			maxPQ.pop();
		}
		while (!minPQ.empty() && !visited[minPQ.top().second])
		{
			minPQ.pop();
		}

		if (minPQ.empty() && maxPQ.empty())
		{
			std::cout << "EMPTY" << "\n";
		}
		else
		{
			std::cout << maxPQ.top().first << " " << minPQ.top().first << "\n";
		}
	}
	
	return 0;
}