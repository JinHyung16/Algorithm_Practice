#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 공유기 설치 - 이분 탐색 알고리즘
/// 
/// 가장 인접한 두 공유기의 사이의 거리를 최대로 해야한다.
/// routers 벡터에 공유기 위치를 다 입력받았으면 정렬하여 가장 작은 값과 큰 값을 우선 선택해두고 시작한다.
/// 이분 탐색을 위해서 left = 0, right = routers[routers.size() - 1], mid = (left + right) / 2로 놓고 시작한다.
/// 1) while(left <= right)를 통해 인접한 두 공유기 사이의 최대 거리값을 찾는다.
/// 2) for문을 통해 공유기들의 거리 차이를 보면서 mid값보다 큰지 작은지 비교해 크면 공유기를 설치하고 index를 설치한 공유기 index 값으로 바꾼다.
/// 3) 전체 설치해야하는 공유기 개수와 현재 설치된 개수를 비교하면서 left 또는 right를 움직여 가며 비교한다.
/// </summary>

using namespace std;

vector<int> routers;

int main(void)
{
	FastIO;
	
	int N = 0, C = 0; //집의 개수 N과 공유기의 개수 C
	std::cin >> N >> C;
	for(int i = 0; i < N ; i++)
	{
		int x = 0;
		std::cin >> x;
		routers.push_back(x);
	}

	std::sort(routers.begin(), routers.end());

	int left = 0;
	int right = routers[routers.size() - 1];
	int maxDist = -1;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		int installCnt = 1, start = 0; //현재 설치한 공유기 개수와 index 번호

		for(int j = 0; j < N; j++)
		{
			if(mid <= routers[j] - routers[start])
			{
				installCnt += 1;
				start = j; //공유기를 설치했으니 방금 설치한 index 번호로 교체한다.
			}
		}

		if(C <= installCnt)
		{
			maxDist = std::max(maxDist, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	std::cout << maxDist << "\n";
	return 0;
}