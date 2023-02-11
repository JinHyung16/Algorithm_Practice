#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 농구 경기 - 문자열 알고리즘
/// 성은 알파벳 소문자이니, 이름의 앞만 int로 변환해 이를 index로 사용하는 vector의 값을 증가시킨다.
/// 알파벳 소문자 a는 -97하면 0을 의미, 0에다가 +97하면 char의 a가 나온다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //선수의 수 N
	string name; //선수 이름 받을 변수

	bool canPlay = false; //출전 선수가 있는지 체크하는 bool
	char lastName = ' '; //출선 선수의 성을 출력하기 위한 변수
	vector<int> lastNameCnt(26, 0); //a~z까지 순서대로 성의 개수를 저장하는 배열

	std::cin >> N;
	while (N--)
	{
		std::cin >> name;
		lastNameCnt[name[0] - 97]++; //해당 알파벳을 숫자로 바꾼 index번호의 개수 증가시키기
	}

	for (int i = 0; i < lastNameCnt.size(); i++)
	{
		if (5 <= lastNameCnt[i])
		{
			canPlay = true;
			lastName = i + 97;
			std::cout << lastName;
		}
	}

	if (!canPlay)
	{
		std::cout << "PREDAJA" << "\n";
	}
	return 0;
}