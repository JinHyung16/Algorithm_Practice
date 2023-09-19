#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 KMP�� �� KMP�ϱ�? - ���ڿ� �˰���
/// �ᱹ ������ ���� �빮�ڸ� ����ϴ�, string[i]�� �빮�ڸ� �װ͸� ���� ��� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	string input;
	std::cin >> input;
	string result;
	for ( int i = 0; i < input.length(); i++ )
	{
		if ( 'A' <= input[i] && input[i] <= 'Z')
		{
			result += input[i];
		}
	}

	std::cout << result << "\n";
	return 0;
}