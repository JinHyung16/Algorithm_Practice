#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

/// <summary>
/// Silver4 문자열 - 브루트포스 알고리즘
/// </summary>

int MIN_DIFFERENCE = 50; //왜냐면 문자열 최대 길이가 50이므로 만약 두 문자열이 다 다르면 최소 50번 필요

int main(void)
{
	string firstString;
	string secondString;

	int lengthDifference = 0;
	int maxMinDifference = MIN_DIFFERENCE;

	cin >> firstString >> secondString;

	lengthDifference = (int)(secondString.length() - firstString.length()); //두 문자열의 길이 차이

	//비슷하게 만들기 위한 최소의 수 -> 얼만큼 일치하냐 == 둘의 차이가 최소인 곳이 어디냐

	for (int i = 0; i <= lengthDifference; i++)
	{
		int curDifference = 0;

		for (int j = 0; j < firstString.length(); j++)
		{
			//둘이 다른 지점을 확인
			if (firstString[j] != secondString[i + j])
			{
				curDifference++;
			}
		}

		//최소한의 다른 지점이 max인 것에 어느 부분이 최소로 다른지 저장
		maxMinDifference = min(maxMinDifference, curDifference);
	}

	cout << maxMinDifference;

	return 0;
}