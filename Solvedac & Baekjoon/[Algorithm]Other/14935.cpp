#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 FA - 애드 혹 알고리즘
/// 1자리 수에 대해서 FA를 실행하면 계속 1자리 수로 무조건 FA다
/// 그렇다면 2자리 수 이상에 대해서 판별하면 된다.
/// 2자리 수 이상 수에 대해서 FA를 진행하면 계속 자리수가 작아진다.
/// 따라서 입력의 길이만큼 FA를 돌려서 자리수가 1자리면 FA 아니면 NFA를 출력하면 된다.
/// </summary>

using namespace std;

string FA(string x)
{
	string temp;
	temp = ((x[0] - '0') * x.size()) + '0';
	return temp;
}

int main(void)
{
	FastIO;

	string x;
	std::cin >> x;

	for ( int i = 0; i < x.size(); i++ )
	{
		x = FA(x);
	}

	if ( x.size() == 1 )
	{
		std::cout << "FA" << "\n";
	}
	else
	{
		std::cout << "NFA" << "\n";
	}
	return 0;
}