#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 ķ�� - Greedy �˰���
/// ex) L=5, P=8, V=20�ΰ��
/// �ִ� 5�� + ���� 3�� + �ִ� 5�� + ���� 3�� + ���� �ϼ�(20 - (5+3+5+3) = 4��) = 20��
/// �̶� ���� �ϼ��� L���� ũ�ٸ� ���� �ϼ��� L�� ����
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int L = 0, P = 0, V = 0; //�����ϴ� P�� ��, L�ϵ��ȸ� ��� ����. V��¥�� �ް� ����
	int testCaseNum = 1;
	while ( true )
	{
		std::cin >> L >> P >> V;
		if ( L == 0 && P == 0 && V == 0 ) break;
		int use = V / P;
		int remain = V % P;
		if ( L < remain )
		{
			remain = L;
		}
		int result = L * use + remain;
		std::cout << "Case " << testCaseNum << ": " << result << "\n";
		testCaseNum++;
	}
	return 0;
}