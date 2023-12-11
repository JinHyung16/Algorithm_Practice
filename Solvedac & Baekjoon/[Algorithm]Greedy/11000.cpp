#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Gold5 강의실 배정 - Greedy 알고리즘
/// vector와 pair를 통해 S,V를 담아둔다.
/// S를 기준으로 오름차순 정렬한다.
/// 그리고 강의를 순서대로 시작하는데
/// 강의를 시작하면 해당 강의 T시간을 우선순위 큐에 삽입한다.
/// 우선순위 큐의 T와 다음 강의 S를 비교해 만약 S가 크거나 같다면 같은 강의실에서
/// 수업이 가능한 것으로 우선순위 큐에서 T를 빼낸다.
/// N번 반복한 후 마지막 우선순위 큐의 사이즈를 보면 필요한 강의 개수다.
/// </summary>


int GetClassCount(vector<pair<int, int>>& vec, int n)
{
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(vec[0].second);

	for (int i = 1; i < n; i++)
	{
		pq.push(vec[i].second);
		if (pq.top() <= vec[i].first)
		{
			pq.pop();
		}
	}

	answer = pq.size();
	return answer;
}

int main(void)
{
	FastIO;
	
	int N = 0;
	cin >> N;

	int S = 0, T = 0; // S부터 T까지 수업
	vector<pair<int, int>> classTime;

	for(int i = 0; i < N; i++)
	{
		cin >> S >> T;
		classTime.push_back(make_pair(S, T));
	}
	sort(classTime.begin(), classTime.end());
	
	cout << GetClassCount(classTime, N);
	return 0;
}