#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 8���� 2���� - ���ڿ� �˰���
/// 8������ �� �ڸ��� 2������ ��ȯ�Ѵ�.
/// ex) 314 => 3(011) 1(001) 4(100)
/// �̶� �� ���� 0�̸� �ȵǹǷ� 11001100���� ����.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string octalToBinary[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
	string octalNum;
	std::cin >> octalNum;

	for ( int i = 0; i < octalNum.length(); i++ )
	{
		int temp = octalNum[i] - '0';
		if ( i == 0 )
		{
			std::cout << std::stoi(octalToBinary[temp]);
		}
		else
		{
			std::cout << octalToBinary[temp];
		}
	}

	return 0;
}