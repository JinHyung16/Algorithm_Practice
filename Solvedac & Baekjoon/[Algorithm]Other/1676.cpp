#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 ���丮�� 0�� ���� - ���� �˰���
/// 
/// 1) ó�� �õ� ��� -> ����
/// recursion�� �̿��ϸ� �ð��ʰ��� �޸� ���鿡�� ��ȿ���̴�.
/// ���� �迭�� ��ư��鼭 memoization�� �̿��� recursion�� ���Ѵ�.
/// ������ N�� 500�϶��� ���̿���. ���� ���ο� ���ٹ��� �����غô�.
/// 
/// 2) ���μ� ���� �̿�
/// ���� 0�� ������ ���� * 10�� ���ۿ� ����.
/// 10�� ���μ� �����ϸ� 2*5��. ���� N!�� ���μ� �����Ͽ� 2�� 5�� ������ ������ ã��
/// �� �� �ּҰ��� ã���� �ȴ�.
/// </summary>

using namespace std;

long long Factorial(int n)
{
	long long twoCnt = 0;
	long long fiveCnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		while (temp % 2 == 0)
		{
			temp /= 2;
			twoCnt += 1;
		}

		while (temp % 5 == 0)
		{
			temp /= 5;
			fiveCnt += 1;
		}
	}

	return std::min(twoCnt, fiveCnt);
}
int main(void)
{
	FastIO;

	int N(0);
	std::cin >> N;

	long long zeroCnt = Factorial(N);

	std::cout << zeroCnt << "\n";
	return 0;
}