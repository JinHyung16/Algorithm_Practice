#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 !�к� ���� - ���ڿ� �˰���
/// getline(cin, string)�� ���� ���ڿ��� ���� �����ؼ� �޴´�.
/// ���ڿ��� �� ���� ������ ���� for���� ��� length - 1 �ؾ���
/// �츮�� ���ϴ� ���ڿ� �� ������ �� ó������ ���ڸ� 1���� ����� �� �ִ�.
/// �ƴϸ� reverse�� ����ؼ� ������ ����Ѵ�.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	while (true)
	{
		string input;
		std::getline(cin, input);

		if (input == "END")
		{
			break;
		}

		std::reverse(input.begin(), input.end());
		std::cout << input << "\n";

		/*
		for (int i = input.length() - 1; 0 <= i; i--)
		{
			std::cout << input[i];
		}
		std::cout << "\n";
		*/
	}

	return 0;
}