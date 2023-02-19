#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 팰린드롬 만들기 - Greedy 알고리즘
/// 팰린드롬은 거꾸로 읽어도 제대로 읽은것과 같은걸 의미
/// 팰린드롬은 홀수인 알파벳이 2개이상 있으면 만들 수 없다.
/// 이전에 소문자는 -37해서 해당 알파벳의 카운트를 증가시켰다면
/// 대문자는 +'A'형태로 사용하면된다.
/// 1)은 원래 이름 순서대로 배치
/// 2)은 홀수개는 중앙에 배치
/// 3)은 역순으로 이름 배치하는 방법이다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string name;
	string palindromeName;
	vector<int> alphabet(26, 0);

	std::cin >> name;
	for (int i = 0; i < name.size(); i++)
	{
		alphabet[name[i] - 'A']++;
	}

	int oddAlphaCnt(0);
	for (int i = 0; i < alphabet.size(); i++)
	{
		if (alphabet[i] % 2 == 1)
		{
			oddAlphaCnt++;
		}
	}

	if (2 <= oddAlphaCnt)
	{
		//홀수개인 알파벳이 2개 이상이면 팰린드롬을 만들 수 없다.
		std::cout << "I'm Sorry Hansoo" << "\n";
		return 0;
	}

	//1) A에서 Z까지 나온 알파벳의 개수/2만큼 알파벳 더해준다
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < alphabet[i]/2; j++)
		{
			palindromeName += (i + 'A');
		}
	}

	//2) 남은 홀수개의 알파벳은 팰린드롬으로 만들 문자 중앙에 배치
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] % 2 == 1)
		{
			palindromeName += (i + 'A');
		}
	}

	//3) Z에서 A까지 나온 알파벳의 개수/2만큼 알파벳 더해준다
	for (int i = 25; 0 <= i; i--)
	{
		for (int j = 0; j < alphabet[i] / 2; j++)
		{
			palindromeName += (i + 'A');
		}
	}

	std::cout << palindromeName << "\n";
	return 0;
}