#include<iostream>
#include<vector>
#include<queue>

typedef long long ll;

/// <summary>
/// Silver2 A->B - Graph 알고리즘
/// BFS를 이용한 풀이
/// queue에다가 연산을 담아두면서 pop시켜간다
/// 이때 while문이 끝났을 때 즉 queue가 비었을 때,
/// 계산 결과를 만족했는지 안했는지에 따라 return을 다르게한다.
/// 이때 pair에는 변형시킬 A와 변형시킨 횟수를 같이 저장해둔다.
/// </summary>

using namespace std;

int BFS(ll a, ll b)
{
	queue<pair<ll, ll>> q;
	q.push(make_pair(a, 1)); //A와 초기에는 변형시킨 횟수가 1이다. 왜냐면 조건에서 마지막 +1해서 출력하니깐

	while (!q.empty())
	{
		//cur.first는 A를 의미, cur.second는 변형시킬때마다 1씩 증가해서 저장
		pair<ll, ll> cur = q.front();
		q.pop();

		if (cur.first == b)
		{
			//변형시키는 A가 B와 같아졌다면, 변형시킨 횟수 리턴
			return cur.second;
		}

		//2를 곱해서 변환시키는 과정
		if (cur.first * 2 <= b)
		{
			q.push({ cur.first * 2, cur.second + 1 });
		}

		//1을 가장 오른쪽에 추가하면 결국 자리수가 한칸 증가하고 1이 붙는거다
		if ((cur.first * 10) + 1 <= b)
		{
			q.push({ (cur.first * 10) + 1, cur.second + 1 });
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	ll A(0), B(0); //A를 B로 바꿔야한다
	std::cin >> A >> B;
	
	std::cout << BFS(A, B) << std::endl;
	return 0;
}