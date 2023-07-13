#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 소음 - 문자열 알고리즘
/// 1) 곱셈의 경우 두 string의 길이 - 1을 하여 실제 수의 길이를 얻어 합친다. 그 후 1로 시작하여 뒤에다가 전체 길이만큼 0으로 채운다.
/// 2-1) 덧셈의 경우 a와 b의 크기를 비교하고, 길이가 큰 쪽에서 작은쪽을 빼서 해당 index값만 1로 바꾸고 나머진 그대로 값을 쓴다.
/// 2-2) 덧셈의 경우 a와 b가 같으면, 맨 앞만 둘 중 아무 값으로 초기화하고 맨 앞만 2로 바꾼뒤 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	string a, b;
	char oper;
	std::cin >> a;
	std::cin >> oper;
	std::cin >> b;

	string result;
	if ( oper == '*' )
	{
		int totalLength = (a.length() - 1) + (b.length() - 1);
		result = "1";
		for ( int i = 0; i < totalLength; i++ )
		{
			result += '0';
		}
		std::cout << result << "\n";
	}
	else
	{
		if ( b.length() < a.length() )
		{
			result = a;
			int index = a.length() - b.length();
			result[index] = '1';
			std::cout << result << "\n";
		}
		else if ( a.length() < b.length() )
		{
			result = b;
			int index = b.length() - a.length();
			result[index] = '1';
			std::cout << result << "\n";
		}
		else
		{
			string result = a;
			result[0] = '2';
			std::cout << result << "\n";
		}
	}
	return 0;
}