#include<iostream>

using namespace std;

int main(void)
{
	int size_N = 0, size_M = 0;

	int divide_size = 1 * 1; //�����ַ��� ũ�� 1*1
	int divide_count = 0; //�����ִ� Ƚ��
	
	cin >> size_N >> size_M;

	//N�� ����, M�� ���ζ� ����
	//ex)2*2(=N*M)�� ��� ���� 1�� �ڸ��� 1*2������ ���ݸ� 2�� ����, 1*2������ 2�� �߶�� ��
	//�ּ� Ƚ�� = N-1 + N*(M-1) �� ��
	
	divide_count = (size_N)-1 + size_N * (size_M - 1);

	cout << divide_count;

	return 0;
}