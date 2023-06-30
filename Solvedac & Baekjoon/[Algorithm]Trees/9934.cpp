#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 완전 이진 트리 - 트리 알고리즘
/// 중위 순회 하고 있으며, 완전 이진 트리는 높이가 H개라면 노드의 수는 2^H - 1개가 되는 무조건 홀수개의 노드를 갖는다.
/// 따라서 root 노드는 정 가운데가 루트 노드다.
/// 
/// 재귀 함수를 이용해 left, right를 나눠서 순환한다.
/// 문제에서 K를 depth 또는 height로 생각해서 해결한다.
/// </summary>

using namespace std;

int K = 0; //1이상 2^K 개 미만의 방문한 노드 개수
vector<int> trees;
vector<int> result[10]; //K의 최대값이 10이므로
void PreOrder(int left, int right, int height)
{
	if(height == K)
	{
		//depth만큼 다 돌았다면 return
		return;
	}

	if(left == right)
	{
		//left값을 해당 depth에 기록하고 return
		result[height].push_back(trees[left]);
		return;
	}

	int midRoot = (left + right) / 2;
	result[height].push_back(trees[midRoot]);
	PreOrder(left, midRoot - 1, height + 1); //왼쪽 순환
	PreOrder(midRoot + 1, right, height + 1); //오른쪽 순환
}

int main(void)
{
	FastIO;
	
	std::cin >> K;

	int maxNode = std::pow(2, K) - 1;
	for(int i = 0; i < maxNode; i++)
	{
		int node = 0;
		std::cin >> node;
		trees.push_back(node);
	}
	
	PreOrder(0, trees.size(), 0);

	for(int i = 0; i < K; i++)
	{
		for(int j = 0; j < result[i].size(); j++)
		{	
			std::cout << result[i][j] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}