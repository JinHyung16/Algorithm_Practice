#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>

/// <summary>
/// Silver5 회사에 있는 사람 - Hash_Set 알고리즘
/// set을 이용하면 중복을 자동으로 제거해주는 트리로
/// 동명이인이 없다는 조건을 만족시키는데 쉽다.
/// set을 이용해 역순 출력시 rbegin(), rend()와 for문의 형태를 잘 보자
/// </summary>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //로그에 기록된 출입 기록의 수 N
	set<string> enterPersonSet;
	
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		string name, log;
		std::cin >> name >> log;

		if (log == "enter")
		{
			enterPersonSet.insert(name);
		}
		else
		{
			enterPersonSet.erase(name);
		}
	}

	for (auto s = enterPersonSet.rbegin(); s != enterPersonSet.rend(); s++)
	{
		std::cout << *s << "\n";
	}

	return 0;
}