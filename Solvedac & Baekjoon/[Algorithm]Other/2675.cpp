#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 ���ڿ� �ݺ� - ���ڿ� �˰���
/// ���� for���� �� �������ָ� �ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int testCase(0);
	std::cin >> testCase;

	while (testCase--)
	{
		int repeatCnt(0);
		string input;
		std::cin >> repeatCnt >> input;
		
		for (int i = 0; i < input.length(); i++)
		{
			for (int j = 0; j < repeatCnt; j++)
			{
				std::cout << input[i];
			}
		}
		std::cout << "\n";
	}
	return 0;
}