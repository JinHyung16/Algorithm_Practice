#include<iostream>
#include<vector>

int main(void)
{
	//�ٸ� �Ǽ��ϱ� dp �˰���
	//m���߿��� n�� �����ϴ� ���� �����ϱ�
	//nCr = n-1Cr-1 + n-1Cr
	//���⼱ m���� n���̱�� mCn

	int testCase = 0;
	int n = 0, m = 0; //����, ���� �ٸ�

	std::cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		std::cin >> n >> m;

		long long dp = 1;

		int r = 1;
		for (int a = m; (m - n) < a; a--)
		{
			// (m * m-1 * ... * m - r + 1) / (n * n-1 * .... * 1) ���� �̿�
			// m/n ���� �����Ͽ� m�� n�� ���� 1�� ���̸鼭 ������
			dp *= a;
			dp /= r;
			r += 1;
		}
		std::cout << dp << std::endl;
	}
	return 0;
}