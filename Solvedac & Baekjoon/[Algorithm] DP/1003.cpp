#include<iostream>
#include<vector>

/*
* Silver3 - �Ǻ���ġ dp �˰��� ����
*/

int main(void)
{
	const int MAX_SIZE = 40; //�迭 �ִ� ������
	int testCase = 0;

	std::vector<int> dpFibonacci(MAX_SIZE + 1);
	dpFibonacci[0] = 0;
	dpFibonacci[1] = 1;

	for (int f = 2; f < dpFibonacci.size(); f++)
	{
		dpFibonacci[f] = dpFibonacci[f - 1] + dpFibonacci[f - 2];
	}

	std::cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int n = 0;
		std::cin >> n;

		if (n == 0)
		{
			std::cout << "1 0" << std::endl;
		}
		else
		{
			//0��� Ƚ���� n�� 0�϶� 1, 1��� Ƚ���� n�� 1�϶� ����
			std::cout << dpFibonacci[n - 1] << " " << dpFibonacci[n] << std::endl;
		}
	}
	return 0;
}