#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze5 ���簢�� - ���� �˰���
/// ���簢���� ���̴� ����*���δ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int A = 0, B = 0; //���� ���� Acm, ���� ���� Bcm
	std::cin >> A >> B;

	std::cout << A * B << "\n";
	return 0;
}