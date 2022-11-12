#include<iostream>
#include<vector>
#include<string>


using namespace std;

/// <summary>
/// Silver5 뒤집기 - greedy 알고리즘
/// ex)11001 입력시 s[1]=1, s[2]=0이다.
/// 즉 이렇게 다른 경우가 생겼을 때, 현재 숫자가 0인지 1인지 보고 해당 숫자 카운팅
/// 그래야 s[3]과 s[4] 비교수 현재 index는 3인데 둘이 다르고, 카운팅 하는 숫자 부분은 0일때로
/// 이는 즉 2~3번째 index를 잡고 counting하는 것과 동일한 효과다
/// </summary>


int main(void)
{
	string s;
	vector<int> counting(2, 0); //0과 1 카운팅 하기

	std::cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != s[i + 1])
		{
			if (s[i] == '0')
			{
				counting[0]++;
			}
			else if (s[i] == '1')
			{
				counting[1]++;
			}
		}
	}

	if (counting[0] < counting[1])
	{
		std::cout << counting[0] << std::endl;
	}
	else
	{
		std::cout << counting[1] << std::endl;
	}

	return 0;
}