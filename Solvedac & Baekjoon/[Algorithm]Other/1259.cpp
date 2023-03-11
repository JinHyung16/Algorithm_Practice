#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 팰린드롬수 - 문자열 알고리즘
/// 입력받은 원래의 수와, 이걸 뒤집은 수 2개를 준비하고
/// 이 두개가 같은지 비교하면 된다.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	int num(0);
	while (true)
	{
		std::cin >> num;
		if (num == 0)
		{
			break;
		}

		string origin = std::to_string(num);
		string copy = origin;
		std::reverse(copy.begin(), copy.end());

		if (origin == copy)
		{
			std::cout << "yes" << "\n";
		}
		else
		{
			std::cout << "no" << "\n";
		}
	}
	return 0;
}