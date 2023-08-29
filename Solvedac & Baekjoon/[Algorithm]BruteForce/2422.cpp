#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 �������� ��Ż���ƿ� ���� ���̽�ũ���� ��Դµ� - ���Ʈ���� �˰���
/// N���� ������ 3�� for���� ���鼭 ij, jk, ik�� ���� �ִٸ� �н��ϰ� �ƴϸ� result�� ������Ų��.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, M = 0; //���̽�ũ�� ���� N, M�� ��������� �� �Ǵ� ������ ����
	std::cin >> N >> M;

	vector<vector<bool>> icecreams(201, vector<bool>(201, false));
	int result = 0;
	for ( int i = 0; i < M; i++ )
	{
		int a = 0, b = 0;
		std::cin >> a >> b;
		icecreams[a][b] = true;
		icecreams[b][a] = true;
	}

	for ( int i = 1; i <= N - 2; i++ )
	{
		for ( int j = i + 1; j <= N - 1; j++ )
		{
			for ( int k = j + 1; k <= N; k++ )
			{
				if ( icecreams[i][j] || icecreams[j][k] || icecreams[i][k] )
				{
					continue;
				}
				result++;
			}
		}
	}

	std::cout << result << "\n";
	return 0;
}