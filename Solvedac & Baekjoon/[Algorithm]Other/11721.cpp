#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 �� ���� ���� ����ϱ� - ���ڿ� �˰���
/// 10���� ���� �������� 9�����Ѵ�.
/// �ֳĸ� index�� 0���� 9������ �� 10���̱� �����̴�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int splitCnt = 10;

	string input;
	std::cin >> input;
	
	for (int i = 0; i < input.length(); i++)
	{
		std::cout << input[i];
		if (i % splitCnt == 9)
		{
			std::cout << "\n";
		}
	}
	return 0;
}