#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 ���� - ���ڿ� �˰���
/// 1) ������ ��� �� string�� ���� - 1�� �Ͽ� ���� ���� ���̸� ��� ��ģ��. �� �� 1�� �����Ͽ� �ڿ��ٰ� ��ü ���̸�ŭ 0���� ä���.
/// 2-1) ������ ��� a�� b�� ũ�⸦ ���ϰ�, ���̰� ū �ʿ��� �������� ���� �ش� index���� 1�� �ٲٰ� ������ �״�� ���� ����.
/// 2-2) ������ ��� a�� b�� ������, �� �ո� �� �� �ƹ� ������ �ʱ�ȭ�ϰ� �� �ո� 2�� �ٲ۵� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	string a, b;
	char oper;
	std::cin >> a;
	std::cin >> oper;
	std::cin >> b;

	string result;
	if ( oper == '*' )
	{
		int totalLength = (a.length() - 1) + (b.length() - 1);
		result = "1";
		for ( int i = 0; i < totalLength; i++ )
		{
			result += '0';
		}
		std::cout << result << "\n";
	}
	else
	{
		if ( b.length() < a.length() )
		{
			result = a;
			int index = a.length() - b.length();
			result[index] = '1';
			std::cout << result << "\n";
		}
		else if ( a.length() < b.length() )
		{
			result = b;
			int index = b.length() - a.length();
			result[index] = '1';
			std::cout << result << "\n";
		}
		else
		{
			string result = a;
			result[0] = '2';
			std::cout << result << "\n";
		}
	}
	return 0;
}