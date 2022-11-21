#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver4 �ٴ� ��� - Graph �̷� 1388��
/// DFS�� �� �������� ���ʴ�� ��� ��带 Ž���ϴ� ��
/// �� ���̵� ������� �������� ���� �� ����, �� ���� �Ʒ��� �������� �ݺ� ��� i,j�迭�� ���ؼ�
/// </summary>


int main(void)
{
	//�� ��� �ӵ� up
	ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	//n�� ����, m�� ����
	int n(0), m(0);
	std::cin >> n >> m;

	vector<vector<char>> woods(n,vector<char>(m));
	int count = 0;

	//2���� �迭���� ���δ� ��, ���δ� ���� �ش�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> woods[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (woods[i][j] == '-')
			{
				//'-'�������� ���ٰ� ���� �࿡ '|'�� ������ �׶����� count ����
				//�ֳĸ� '-'�� ���� �࿡ ���ؼ� 1���� ����ϱ� ����
				if (j == m - 1 || woods[i][j + 1] == '|')
				{
					count++;
				}
			}
			if (woods[i][j] == '|')
			{
				// '|' �Ʒ��� �������ٰ� ���� ���� '-'�� ������ �׶����� count ����
				// �ֳĸ� '|'�� ���� ���� ���ؼ� 1���� ����ϱ� ����
				if (i == n - 1 || woods[i + 1][j] == '-')
				{
					count++;
				}
			}
		}
	}

	std::cout << count;
	return 0;
}