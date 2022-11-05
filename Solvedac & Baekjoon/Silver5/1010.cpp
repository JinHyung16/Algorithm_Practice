#include<iostream>
#include<vector>

int main(void)
{
	//다리 건설하기 dp 알고리즘
	//m개중에서 n개 선택하는 조합 생각하기
	//nCr = n-1Cr-1 + n-1Cr
	//여기선 m개중 n개뽑기로 mCn

	int testCase = 0;
	int n = 0, m = 0; //서쪽, 동쪽 다리

	std::cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		std::cin >> n >> m;

		long long dp = 1;

		int r = 1;
		for (int a = m; (m - n) < a; a--)
		{
			// (m * m-1 * ... * m - r + 1) / (n * n-1 * .... * 1) 임을 이용
			// m/n 에서 시작하여 m과 n을 각각 1씩 줄이면서 곱하자
			dp *= a;
			dp /= r;
			r += 1;
		}
		std::cout << dp << std::endl;
	}
	return 0;
}