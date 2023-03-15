#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 ���� ��� 1 - ���� �˰���
/// ���� ��� ������ N!/((N-K)! * K!)�̴�.
/// �̶� ���丮�� ���ϴ� �κи� �����ϸ� �ȴ�.
/// �̶�, vector�� �̿��� vec[i]�� i������ ���丮�� ����� ���� �����ϰ� �ִ´�.
/// </summary>

using namespace std;

int Factorial(int n)
{
	vector<int> vec(n + 1, 0);
	vec[0] = 1;
	
	for (int i = 1; i <= n; i++)
	{
		vec[i] = i * vec[i - 1];
	}
	
	return vec[n];
}

int main(void)
{
	FastIO;
	
	int N(0), K(0); //�ڿ��� N�� ���� K
	std::cin >> N >> K;

	int result = Factorial(N) / (Factorial((N - K)) * Factorial(K));

	std::cout << result << "\n";
	return 0;
}