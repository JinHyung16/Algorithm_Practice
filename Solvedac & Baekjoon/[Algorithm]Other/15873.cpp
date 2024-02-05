#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 공백 없는 A+B - 구현 알고리즘
/// 공백 없는 입력은 char나 string으로 받으면 된다.
/// 문제에서 두 수 는 모두 10이하로 최대 2리다.
/// 그러니 string.size()를 2로 나눠 a먼저 자리수 할당하고
/// string.size() - a.size()하면 남은 b의 자리수이다.
/// 이를 이용해 string.substr로 a와 b를 나눈다.
/// </summary>


int main(void)
{
	FastIO;

	string input;
	cin >> input;

    int result = 0;
    if ( input.size() == 2 )
    {
        result = (input[0] - '0') + (input[1] - '0');
    }
    else if ( input.size() == 3 )
    {
        int aSize = input.size() / 2 + input.size() % 2;
        string a, b;
        if ( input[1] == '0' )
        {
            a = input.substr(0, aSize);
            b = input.substr(aSize);
        }
        else
        {
            a = input.substr(0, aSize - 1);
            b = input.substr(aSize - 1);
        }

        result = stoi(a) + stoi(b);
    }
    else
    {
        int aSize = input.size() / 2 + input.size() % 2;

        string a = input.substr(0, aSize);
        string b = input.substr(aSize);

        result = stoi(a) + stoi(b);
    }

	std::cout << result << "\n";
	return 0;
}