#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver3 바이러스 - Graph 이론
/// DFS를 이용해 한쪽 방향으로 끝까지 방문하고
/// 그 다음 옮겨서 방문하기
/// vector 선언시 이차원으로 이용하는 방법 익혀보자!
/// </summary>

vector<int> dfsVec[101];
bool isVisit[101] = { false, };
int virusCount = -1;

void DFSFunction(int cur)
{
	if (isVisit[cur])
	{
		return;
	}

	virusCount++;
	isVisit[cur] = true;
	for (auto index = dfsVec[cur].begin(); index < dfsVec[cur].end(); index++)
	{
		DFSFunction(*index);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int computeCount = 0;
	int pairCount = 0;

	int nodeOne = 0, nodeTwo = 0;
	std::cin >> computeCount >> pairCount;

	for (int i = 0; i < pairCount; i++)
	{
		std::cin >> nodeOne >> nodeTwo;
		dfsVec[nodeOne].push_back(nodeTwo);
		dfsVec[nodeTwo].push_back(nodeOne);
	}
	
	DFSFunction(1);
	std::cout << virusCount << std::endl;
	return 0;
}