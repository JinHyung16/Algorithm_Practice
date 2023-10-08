#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze1 �ּҰ���� - ���� �˰���
/// �ּ� ������� ã�� ���ؼ� �ִ� ������� ���� ���Ѵ�.
/// �� �� �� ���� �ִ� ������� ���� ���� �������� �ִ������� ���Ѵ�.
/// </summary>

int GreatDivisor(int a, int b)
{
	if ( a % b == 0 )
		return b;
	else
		return GreatDivisor(b, a % b);
}

int main(void)
{
	FastIO;

	int T = 0; //�׽�Ʈ ���̽� T
	int A = 0, B = 0;
	cin >> T;
	while ( T-- )
	{
		cin >> A >> B;
		if ( B <= A )
			cout << A * B / GreatDivisor(A, B) << "\n";
		else
			cout << A * B / GreatDivisor(B, A) << "\n";
	}
	return 0;
}