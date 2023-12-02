#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze2 더하기 - 파싱 알고리즘
/// ,가 나오기 전까지 값들을 수로 바꿔 더한다.
/// string 헤더에 stoi를 사용하면 string을 int로 변환할 수 있다.
/// </summary>

int main(void)
{
	FastIO;

	string input;
	cin >> input;

	int sum = 0;
	string tmp;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] != ',')
		{
			tmp += input[i];
		}
		else
		{
			sum += stoi(tmp);
			tmp.clear();
		}
	}
	sum += stoi(tmp);

	cout << sum << "\n";
	return 0;
}