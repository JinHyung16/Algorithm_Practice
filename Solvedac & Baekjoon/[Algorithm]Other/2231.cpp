#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 ������ - ���Ʈ���� �˰���
/// �־��� ������ N�� ���� M�� ã������ ������ ���� �����Ѵ�.
/// 1) 1���� N������ �������� �� ���ؼ� sum���ٰ� �����ϰ� �ִ´�.
/// 2) sum == N�� �� ����, i�� ���� �������̹Ƿ� �ش� i�� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //������ N
	std::cin >> N;

	int sum(0);
	int constructorNum(0);

	for (int i = 1; i <= N; i++)
	{
		sum = i;
		int temp = i;
		while (temp > 0)
		{
			sum += (temp % 10);
			temp /= 10;
		}

		if (sum == N)
		{
			constructorNum = i;
			break;
		}
	}

	std::cout << constructorNum << "\n";
	return 0;
}