#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 ���׽�Ʈ - Sort �˰���
/// Ǯ��1)
/// 0~9���� �� 10���� W���п� 10~19���� �� 10���� K���п� �Է� �޴´�.
/// �� �� sort(vector.rbegin(), vector.rend());�� ���� �������� �����Ѵ�.
/// for i to 3�� ���� 3���� ���� ���� ����Ѵ�.
/// 
/// Ǯ��2)
/// pair<int,int>�� ���� W�� K�� ���� ���� first�� ������ second�� ����ؼ�
/// bool Compare(int a, int b)�� ���� second������ �������� �Ͽ� ���ص� �ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int sumW = 0, sumK = 0; //W������ ���� ���� 3�� ���� ��, K������ ���� ���� 3�� ���� ��
	//W���� ������ K���� ���� ���� vector
	vector<int> W;
	vector<int> K;
	for ( int i = 0; i < 20; i++ )
	{
		int input = 0;
		std::cin >> input;
		if ( i <= 9 )
		{
			W.push_back(input);
		}
		else
		{
			K.push_back(input);
		}
	}

	std::sort(W.rbegin(), W.rend());
	std::sort(K.rbegin(), K.rend());

	for ( int i = 0; i < 3; i++ )
	{
		sumW += W[i];
		sumK += K[i];
	}

	std::cout << sumW << " " << sumK << "\n";
	return 0;
}