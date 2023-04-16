#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ��� ã�� - Graph �˰���
/// �÷��̵� �ͼ� �˰����� �˰Ե� ������.
/// ��� �������� �ٸ� ��� ���������� �ִ� ��θ� ��� ���ؾ��ϴ� ��쿡 ���ȴ�. �̶� �ѹ��� ���Ѵ�.
/// 
/// i��� j���� ���� (i,j)���ҿ� ���� n -> for(n to ������){for(i to ������){for(j to ������)}}
/// �⺻ ��ȭ���� distance[i,j] = min(distance[i,j], distance[i,n]+distance[n,j]))
/// </summary>

using namespace std;

vector<vector<int>> matrix(101, vector<int>(101, 10000));

int main(void)
{
	FastIO;
	
	int N(0); //������ ���� N
	std::cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> matrix[i][j];
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = 10000;
			}
		}
	}

	for (int n = 0; n < N; n++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				matrix[i][j] = std::min(matrix[i][j], matrix[i][n] + matrix[n][j]);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] == 10000)
			{
				std::cout << 0 << " ";
			}
			else
			{
				std::cout << 1 << " ";
			}
		}
		std::cout << "\n";
	}

	return 0;
}