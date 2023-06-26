#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 N-Queen - ���Ʈ���� �˰���
/// 
/// N-Queen�� ��Ʈ��ŷ �˰����� ��ǥ���� ������.
/// Queen�� Ư���� ü���� �� ��� �Ѱ��� ���� ���� �����ϱ⿡ ���⼭���� ���� �����Ѵ�. (���� �ٸ� ���� ���� �� �Ǵ� ���� ��ġ�� �� ����)
/// ���� 2���� �迭�� ����� ��� 1���� �迭�� �ذ��Ͽ� �ð� ���⵵�� �����Ѵ�.
/// 
/// column[0] = i�� 0��° ���� i��° ���� ��ġ�� �ִ� ���̴�. �̷��� �Ͽ� i���� ���� ���� �ʵ��� ��ġ�ϴ� ����� ���� ��� ã�´�.
/// ���� ���� ���ο� �ְų�, �밢���� ������ �ȵǹǷ� �̸� üũ�Ѵ�.
/// 
/// ��Ʈ��ŷ�� �Ϲ������� ����� ���·� �ۼ��Ǵµ�,
/// 1) ��͸� �����ϴ� ���� ���� ���� depth(�Ǵ� level)�� �Ű������� �ֱ�
/// 2) ��Ͱ� ����Ǵ� �������� ������ ����
/// 3) ��Ͱ� �������̸� ����ġ��(��Ʈ��ŷ)�� ����
/// �� 3������ �ۼ��ؾ� �Ѵ�.
/// </summary>

using namespace std;

int N = 0; //N * N ũ���� ü����
int totalNQueen = 0;
vector<int> column(16, 0);

void NQueen(int c)
{
	if(c == N)
	{
		totalNQueen++;
	}
	else
	{
		for(int i = 0; i < N; i ++)
		{
			column[c] = i; //�� ��ġ ���ϱ�
			bool canSetQueen = true;
			for(int j = 0; j < c; j ++)
			{
				if(column[c] == column[j] || std::abs(column[c] - column[j]) == c - j)
				{
					canSetQueen = false;
					break;
				}
			}
			if ( canSetQueen )
			{
				NQueen(c + 1);
			}
		}
	}
}

int main(void)
{
	FastIO;

	std::cin >> N;
	NQueen(0);
	std::cout << totalNQueen << "\n";
	return 0;
}