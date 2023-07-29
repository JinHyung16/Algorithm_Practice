#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 �� �� - ���ڿ� �˰���
/// ���� ��� ���� 1000000�̶��, ab�� ��ġ�� 10000001000000, cd�� ��ġ�� 10000001000000��.
/// ���� �� ���� ���� ������ ����� ������ �߱⿡, long long���� �ٲٱ� ���� stoll(string)�� �̿��Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string a, b, c, d; //�Է¹��� A, B, C, D
	string left, right;
	std::cin >> a >> b >> c >> d;

	left = a + b;
	right = c + d;

	long long result = std::stoll(left) + std::stoll(right);
	
	std::cout << result << "\n";
	return 0;
}