#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ���� - Greedy �˰���
/// rope[i]�� i��° rope�� �ߵ� �� �ִ� �ִ� �߷��� �ǹ��ϸ�
/// �� ������ �� �� �ִ� �߷��� ������ ��ƿ �� �ִ� �ִ� �߷�������.
/// ������ ���� 10, 15�϶� �� ������ 10�� �߷��� �ΰ��ؾ� ù ��° ������ �����ϴ�
/// �ִ� �ߵ� �� �ִ� ���Դ� 10 + 10�ؼ� 20�̴�.
/// ��, ���������� �� rope[i] * i�� �� �� �ִ밪�� ã���� �ȴ�.
/// ����) ������������ sort�� ���� vector����� �̸� ���ϸ� OutOfBounds�� ���.
/// ���� N�� �Է¹ް� resize�� N��ŭ size�� �ٲٴ��� �ƴϸ� N�� ���� �� vector�� ������
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0);
	std::cin >> N;

	vector<long long> rope(N, 0);

	for (int i = 0; i < N; i++)
	{
		std::cin >> rope[i];
	}

	std::sort(rope.begin(), rope.begin() + N, std::greater<long long>());

	long long maxWeight = 0;
	for (int i = 0; i < N; i++)
	{
		//�� i�� �ƴ� i+1�̳ĸ� i�� 0���� �����ε� ������ 1������ �����ؾ��ϴ�
		long long temp = rope[i] * (i + 1);
		maxWeight = std::max(maxWeight, temp);
	}
	std::cout << maxWeight << "\n";
	
	return 0;
}