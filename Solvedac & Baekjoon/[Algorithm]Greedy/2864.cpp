#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 5�� 6�� ���� - �׸��� �˰���
/// string���� �Է¹ް� 5�� �κ��� 6���� �ٲ� �ѹ� �����ϰ�,
/// 6�� �κ��� 5�� �ٲ� �����Ѵ�.
/// �� �� �� �� ���갪�� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string a, b;
	std::cin >> a >> b;

	for ( int i = 0; i < a.length(); i++ )
	{
		if ( a[i] == '6' )
		{
			a[i] = '5';
		}
	}
	for ( int i = 0; i < b.length(); i++ )
	{
		if ( b[i] == '6' )
		{
			b[i] = '5';
		}
	}
	int fiveSum = std::stoi(a) + std::stoi(b);
	for ( int i = 0; i < a.length(); i++ )
	{
		if ( a[i] == '5' )
		{
			a[i] = '6';
		}
	}
	for ( int i = 0; i < b.length(); i++ )
	{
		if ( b[i] == '5' )
		{
			b[i] = '6';
		}
	}
	int sixSum = std::stoi(a) + std::stoi(b);

	std::cout << fiveSum << " " << sixSum << "\n";
	return 0;
}