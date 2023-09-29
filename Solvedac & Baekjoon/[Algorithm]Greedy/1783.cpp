#include<iostream>
#include<algorithm>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ���� ����Ʈ - �׸��� �˰���
/// N�� ���� �����̴� Ƚ���� �޶�����.
/// N=1�� ���� �̵� �Ұ����Ͽ� 1
/// N=2�� �̵� ��� 2, 3���� ���� (M-1)/2+1�̴�. +1�� ó�� ����Ʈ ��ġ�� �ǹ�
/// 3 <= N�̸� ���� ���̿� ���� ������.
/// ���ΰ� 7ĭ �̻��� ���� 1, 2, 3, 4 �̵���� �� �����Ͽ� �� M-2�� ���� ����
/// ���ΰ� 7ĭ �̸��̸� 1, 4 �̵������ ����Ͽ� Mĭ ��ŭ �̵� �����ϳ� ���� ���ǿ� ���� �ִ� 4ĭ���� ����
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, M = 0; //N*M ü����, ���� N ���� M
	std::cin >> N >> M;

	int maxMoveCnt = 0;
	switch ( N )
	{
		case 1:
			maxMoveCnt = 1;
			break;
		case 2:
			maxMoveCnt = std::min(4, (M - 1) / 2 + 1);
			break;
		default:
			if ( M < 7 )
			{
				maxMoveCnt = std::min(M, 4);
			}
			else
			{
				maxMoveCnt = M - 2;
			}
			break;
	}

	std::cout << maxMoveCnt << "\n";
	return 0;
}	