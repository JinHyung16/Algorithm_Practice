#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 나무 자르기 - 이분탐색 알고리즘
/// 먼저 가장 긴 나무를 가져와 절반 나눈 값으로 자를 수 있는 나무들을 자른다.
/// 자르고난 길이를 축적하면서 집으로 가져가려는 나무 길이와 비교를 하고,
/// 만약 아직 모자르다면 end를 mid에서 1씩 빼보면서 자를 수 있는 나무들을 늘려간다.
/// 만약 가져가려는 길이를 초과했다면 start를 mid에서 1씩 더하면서 가져갈 수 있는 나무를 줄여가면서 절단기에 설정할 최대 높이를 찾아간다.
/// 
/// 주의할게 현재 세팅된 절단기 길이(mid)로 자르고 난 뒤 남은 나무의 길이들 축적시 int타입으로 하면 안된다.
/// 우선 주어진 나무의 높이 최대값을 보면 만약 나무가 매우 많은데 다 최대값이면 int를 벗어나기에 long long으로 변경
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0), M(0); //나무의 수N, 집으로 가져가려는 나무의 길이 M
	std::cin >> N >> M;

	vector<int> treeVec(N, 0);
	int maxHeight(0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> treeVec[i];
	}

	int start(0), end(0);
	for (int i = 0; i < N; i++)
	{
		end = std::max(end, treeVec[i]);
	}

	while (start <= end)
	{
		long long curTreeHeight = 0; //현재 세팅된 절단기 길이(mid)로 자르고 난 뒤 남은 나무의 길이들 축적
		int mid = (start + end) / 2;
		for (int i = 0; i < N; i++)
		{
			if (mid < treeVec[i])
			{
				curTreeHeight += (treeVec[i] - mid);
			}
		}
		if (curTreeHeight < M)
		{
			end = mid - 1;
		}
		else
		{
			maxHeight = mid;
			start = mid + 1;
		}
	}

	std::cout << maxHeight << "\n";
	return 0;
}