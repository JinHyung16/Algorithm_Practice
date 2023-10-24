#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 �� �Դ� ȣ���� - DP �˰���
/// ù °���� �� �� A��
/// �� °���� �� �� B��
/// �� °���� �� �� A+B��
/// �� °���� �� �� A+2B��
/// �ټ� °���� �� �� 2A+3B��
/// 
/// �� D��° ���� �� ���� ����� (D-3)A + (D-2)B��.
/// �� ���� ����� ��Ȯ�� �˾ƾ� ���� �� �ִ� �Ǻ���ġ ���� ����
/// 
/// A[a]=b�� a��°�� ȣ���̿��� �� ���� ����� ���� �� ��� b
/// B[a]=b�� a��°�� ȣ���̿��� �� ���� ����� ���� �� ��� b
/// �� ù °���� ȣ���̿��� �� ���� �� ����� �̿��ϸ� 1A+0B=A
/// �� °���� ȣ���̿��� �� ���� �� ����� �̿��ϸ� 0A+1B=B
/// ...D��° �� A[D]=A[D-1]+A[D-2], B[D]=B[D-1]+B[D-2]
/// 
/// ���ô� 6��° ���� 3A+5B = 41�� �����ؾ� �ϹǷ�
/// A=1�̸�, 5B = 38�� ��ⷯ ������ ���� ���� ���������� Ȯ���Ѵ� 
/// </summary>


int main(void)
{
	FastIO;

	int D = 0, K = 0; //�Ѿ�� �� D, �� ���� ���� K
	cin >> D >> K;
	vector<int> A(D + 1, 0);
	vector<int> B(D + 1, 0);

	A[1] = 1, A[2] = 0;
	B[1] = 0, B[2] = 1;
	
	for ( int i = 3; i <= D; i++ )
	{
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}

	for ( int i = 1; i <= K; i++ )
	{
		int mod = K - (A[D] * i);
		if ( mod % B[D] == 0 )
		{
			cout << i << "\n" << mod / B[D] << "\n";
			break;
		}
	}
	return 0;
}