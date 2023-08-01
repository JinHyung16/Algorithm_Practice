#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 �Խ� ���� - ���ڿ� �˰���
/// std::tolwer(string)�� �빮�ڸ� �ҹ��ڷ� �ٲ��ִ� �Լ���.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0; //N���� �Խ���

	std::cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		string input;
		std::cin >> input;
		for ( int i = 0; i < input.length(); i++ )
		{
			if ( 'A' <= input[i] <= 'Z' )
			{
				input[i] = std::tolower(input[i]);
			}
			else
			{
				continue;
			}
		}
		std::cout << input << "\n";
	}

	return 0;
}