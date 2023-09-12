#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ������ �� - ���� �˰���
/// S�� ���� ���� A�� �׻� �����ϹǷ� (1,2) (1,3) (2,3)�� ���� ù ���� �˾ƾ��Ѵ�.
/// �ֳĸ� i==j�� ���� S(i,j)�� 0�̹Ƿ�
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0;
	std::cin >> N;
	vector<vector<int>> S(N + 1, vector<int>(N + 1, 0));
	vector<int> A(N + 1, 0);

	for ( int i = 1; i <= N; i++ )
	{
		for(int j = 1; j <= N; j++)
		{
			std::cin >> S[i][j];
		}
	}

	if ( N == 2 )
		std::cout << "1 1" << std::endl;
	else
	{
		int first = (S[1][2] + S[1][3] - S[2][3]) / 2;
		for ( int i = 1; i <= N; i++ )
		{
			if ( i == 1 )
			{
				A[i] = first;
			}
			else
			{
				A[i] = S[1][i] - first;
			}
			std::cout << A[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}