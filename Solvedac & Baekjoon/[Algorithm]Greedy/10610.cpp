#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 30 - Greedy �˰���
/// 0���� �������� �����Ƿ�, ���� ���� string���� �ް� �������� �����Ѵ�.
/// 30�� ����� ������ ���� ������ 0�̴�.
/// long long�� �־ �ش� ���� 3���� ���� �������� 0�̸� ��� �ƴϸ� -1 ����Ѵ�.
/// �� 3���� ������? string 30�� char�� �ɰ��� ���ϸ� 3�̹Ƿ�
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string N;
	std::cin >> N;
	std::sort(N.begin(), N.end(), std::greater<>());
	if (N[N.length() - 1] != '0')
	{
		//������ ���� 0�� �ƴ϶��
		std::cout << -1 << "\n";
		return 0;
	}

	long long result(0);
	for (char c : N)
	{
		//string�� �տ������� 1���� char�� �о int�� ��ȯ�� ���سִ´�
		result += (c - '0');
	}

	if (result % 3 == 0)
	{
		std::cout << N << "\n";
	}
	else
	{
		std::cout << -1 << "\n";
	}
	return 0;
}