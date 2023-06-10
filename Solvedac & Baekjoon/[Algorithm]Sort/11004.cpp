#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 K��° �� - ���� �˰���
/// vector�� ���� �޾� �� ��, sort�Ͽ� k��° index�� ����Ѵ�.
/// �̶� vector�� index�� ���� ������ 1 �����Ƿ� k-1�ؼ� �ִ´�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0), K(0); //N���� ��, K��° ��
	std::cin >> N >> K;

	vector<int> numVec(N, 0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> numVec[i];
	}

	std::sort(numVec.begin(), numVec.end());
	std::cout << numVec[K - 1] << "\n";
	return 0;
}