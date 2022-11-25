#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver3 ���̷��� - Graph �̷�
/// DFS�� �̿��� ���� �������� ������ �湮�ϰ�
/// �� ���� �Űܼ� �湮�ϱ�
/// vector ����� ���������� �̿��ϴ� ��� ��������!
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