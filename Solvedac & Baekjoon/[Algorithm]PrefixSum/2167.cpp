#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 2���� �迭�� �� - ������ �˰���
/// �������� ����  x <= N, y <= M���� �迭�� ������ [y][x]�� �ƴ� [x][y]��.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0, M = 0; //�迭�� ũ�� N, M
	int K = 0; //���� ���� �κ��� ���� K
	std::cin >> N >> M;

	vector<vector<long long>> prefix(N + 1, vector<long long>(M + 1, 0));
	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= M; j++ )
		{
			std::cin >> prefix[i][j];
			prefix[i][j] += prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
		}
	}
	std::cin >> K;
	for ( int k = 0; k < K; k++ )
	{
		int i = 0, j = 0, x = 0, y = 0;
		std::cin >> i >> j >> x >> y;
		std::cout << prefix[x][y] - prefix[i - 1][y] - prefix[x][j - 1] + prefix[i - 1][j - 1] << "\n";
	}
	return 0;
}