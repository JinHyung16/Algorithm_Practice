#include<iostream>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 잃어버린 괄호 - Greedy 알고리즘
/// 조건1) 가장 처음과 마지막은 숫자다.
/// 조건2) 연속해서 두 개 이상의 연산자 나타나지 않는다.
/// 조건3) 5자리보다 많이 연속되는 숫자는 없다.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	string input;
	std::cin >> input;

	int result(0);
	string caculateNum;
	bool isMinus = false; //plus인지 minus인지 구분해주는 변수

	for (int i = 0; i <= input.size(); i++)
	{
		//+, -또는 문자 맨 끝이면 계산한다.
		if (input[i] == '+' || input[i] == '-' || i == input.size())
		{
			if (isMinus)
			{
				result -= stoi(caculateNum);
				caculateNum = " ";
			}
			else
			{
				result += stoi(caculateNum);
				caculateNum = " ";
			}
		}
		else
		{
			//그 외에는 연속되는 숫자니 string에 연속해서 넣어준다.
			caculateNum += input[i];
		}

		if (input[i] == '-')
		{
			isMinus = true;
		}
	}

	std::cout << result << "\n";

	return 0;
}