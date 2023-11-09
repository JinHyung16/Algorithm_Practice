#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 ��ҹ��� �ٲٱ� - ���� �˰���
/// �ƽ�Ű �ڵ忡�� �ҹ��� 'a'�� �빮�� 'A'�� 32�� ���̳���.
/// �ƽ�Ű �ڵ忡�� A-Z = 65-90
/// �ƽ�Ű �ڵ忡�� a-z = 97-122
/// </summary>


int main(void)
{
	FastIO;

	string input;
	cin >> input;

	for ( int i = 0; i < input.size(); i++ )
	{
		if ( 'A' <= input[i] && input[i] <= 'Z' )
		{
			input[i] += 32;
		}
		else if ( 'a' <= input[i] && input[i] <= 'z' )
		{
			input[i] -= 32;
		}
	}

	cout << input << "\n";

	return 0;
}