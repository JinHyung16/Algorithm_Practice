#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver2 �ζ� - ���շ� �˰���
/// K�� S�� �־��� �� ������ ���� �׻� 6���� �̴°� ���� �ζǴ�.
/// �� �� ������ �� �����ϸ� DFS�� ���ٰ� depth�� 6�̸� �ζ� 6���� �̾����� ��� �� ���߸� �ȴ�.
/// </summary>

vector<int> S;
int lotto[6];

void DFS(int start, int depth, int k)
{
	if ( depth == 6 )
	{
		for ( int i = 0; i < 6; i++ )
			cout << lotto[i] << " ";
		cout << "\n";
		return;
	}

	for ( int i = start; i < k; i++ )
	{
		lotto[depth] = S[i];
		DFS(i + 1, depth + 1, k);
	}
}

int main(void)
{
	FastIO;

	int K = 0; //K���� ��
	while ( true )
	{
		cin >> K;
		if ( K == 0 )
			break;
		S.resize(K, 0);
		for ( int i = 0; i < K; i++ )
		{
			cin >> S[i];
		}
		DFS(0, 0, K);
		cout << "\n"; //���⿡ �־���� �� �׽�Ʈ ���̽����� ����� ���е�
	}
	return 0;
}