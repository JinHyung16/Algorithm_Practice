#include<iostream>
#include<vector>


#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver3 N�� M (2) - Graph �˰���
/// ��Ʈ��ŷ�� �̿��� Ǯ��
/// DFS�� ���� M�� depth�� �����Ͽ� �����Ѵ�.
/// M�� ������� for���� ���� 1���� N���� sequence vector�� m��°�� for���� i���� �����Ѵ�.
/// �� �� DFS�� ������ �� �ܰ辿 ������Ų��.
/// </summary>


int N = 0, M = 0; //1 ���� N���� �ڿ��� �� �ߺ����� M���� ����
vector<int> sequence;

void DFS(int n, int m)
{
	if ( m == M )
	{
		for ( int i = 0; i < M; i++ )
		{
			cout << sequence[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		for ( int i = n; i <= N; i++ )
		{
			sequence[m] = i;
			DFS(i + 1, m + 1);
		}
	}
}

int main(void)
{
	FastIO;

	cin >> N >> M;
	sequence.resize(M + 1, 0);
	DFS(1, 0);
	return 0;
}