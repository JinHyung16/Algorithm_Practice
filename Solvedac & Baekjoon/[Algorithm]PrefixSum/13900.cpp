#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 �������� ���� �� - ���� �˰���
/// ���� ���� 2,3,4�� �������� ����
/// result = (2*3) + (2*4) + (3*4)��
/// ������ �̷��� Ǯ�� �ð� ������ �ɸ��� ����� �ٲ۴�.
/// sum = 2+3+4�� �Ѵ�.
/// �� �� result���� 2*(9-2) + 3 *(9-3) + 4* (9-4)�� �����Ѵ�.
/// �� �ǹ̴� ��� ���ڰ� �ٸ� ���ڵ�� �� ����� ���̴�. �̶� �ߺ��Ǵ°� ������ result / 2�� �����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //�Է� ���� ������ ���� N
	std::cin >> N;
	vector<long long> prefix(N, 0);
	long long sum = 0, result = 0;
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> prefix[i];
		sum += prefix[i];
	}

	for ( int i = 0; i < N; i++ )
	{
		result += prefix[i] * (sum - prefix[i]);
	}
	std::cout << result / 2 << "\n";
	return 0;
}