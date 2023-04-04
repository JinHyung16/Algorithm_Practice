#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 좌표 압축 - 정렬 알고리즘
/// 문제의 의미는 다음과 같다.
/// 들어온 값들중에 i번째기준 나보다 작은 값들이 있는지 보고 그 개수를 X'i로 표현하는 것이였다.
/// 즉 좌표를 압축한다는건 i번째 값을 들어온 값들중 i보다 작은 값들의 개수로 대체한다는 것을 의미
/// 
/// vector<pair<int,int>>를 이용해 해당 값과, 순서를 저장해뒀다.
/// 그리고 같은 vector<pair<int,int>> 배열을 하나 더 만들고, 기존 배열을 오름차순 정렬해둔다.
/// 기존 배열을 돌면서, 중복되는 값이면 새로운 배열에다가 (원래 들어온 순서, 나보다 작은 값들의 개수)로 저장
/// 
/// 작은 값들 개수 저장시 전위연산자를 사용해야 n=n+1에서 앞에 n이 저장되고, 후위연산자를 사용하면 뒤의 n+1에 있는 n이 저장됨을 다시한번 배웠다.
/// 따라서 후위 연산자 사용시 값이 1개 적게 나올수 있으니 조심하자.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	int N(0); //N개의 좌표
	std::cin >> N;

	vector<pair<int, int>> position;
	vector<pair<int, int>> result;
	int minCnt(0); //나보다 작은 개수들

	for(int i = 0; i < N; i++)
	{
		int input(0);
		std::cin >> input;
		position.push_back({ input, i });
	}
	std::sort(position.begin(), position.end());

	result.push_back({ position[0].second, 0 });
	for (int i = 1; i < N; i++)
	{
		//중복되는 값이면
		if (position[i - 1].first == position[i].first)
		{
			result.push_back({ position[i].second,minCnt }); //나보다 작은값이 없으니 개수 0개
		}
		else
		{
			//나보다 작은 값들은 내 기준 앞에있는 수만큼 중가
			result.push_back({ position[i].second, minCnt += 1 }); //전위 연산자(++minCnt) 또는 다음과 같이 사용
		}
	}

	std::sort(result.begin(), result.end());
	for (int i = 0; i < N; i++)
	{
		std::cout << result[i].second << " ";
	}
	return 0;
}