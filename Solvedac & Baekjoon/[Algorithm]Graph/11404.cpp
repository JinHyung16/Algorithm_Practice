#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 �÷��̵� - Graph �˰���
/// �÷��̵� ���� �˰����� �̿��� �ذ��Ѵ�.
/// �÷��̵� ������ �� �� �����Ͽ� ��� ��� �� �ִ� ��θ� ���� �� ����Ѵ�.
/// ���� ������ ���ؼ��� ����� �� ������ �ð� ���⵵�� O(n^3)���� �׷����� ũ�Ⱑ ���� ��쿡 �����ϴ�.
/// </summary>

using namespace std;

vector<vector<int>> cities(101, vector<int>(101, 0));

int main(void)
{
	FastIO;
	
	int n(0), m(0); //������ �� n, ������ ���� m
	std::cin >> n;
	std::cin >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				cities[i][j] = 0;
			}
			else
			{
				cities[i][j] = 987654321;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a(0), b(0), c(0); //���� ���� a, ���� ���� b, ��� c
		std::cin >> a >> b >> c;
		cities[a][b] = std::min(cities[a][b], c);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cities[i][j] = std::min(cities[i][j], cities[i][k] + cities[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cities[i][j] == 987654321)
			{
				std::cout << 0 << " ";
			}
			else
			{
				std::cout << cities[i][j] << " ";
			}
		}
		std::cout << "\n";
	}

	return 0;
}