#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 문자열 집합 - 자료구조 알고리즘
/// 1) N개의 문자열을 중복없이 입력받고,
/// 2) 입력받은걸 토대로 M개를 입력받을 때 만약 중복된다면 이때 카운팅을 해주면 총 몇개가 있는지 알 수 있다.
/// 
/// c++의 STL중 map을 사용하면 된다.
/// map은 pair<key, value> 쌍으로 insert한다.
/// map<key, value>로 이뤄진 레드블랙트리로 검색, 삽입, 삭제가 O(log n) 걸린다.
/// map은 기본적으로 오름차순 정렬이다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0, M = 0; //집합에 있는 N개의 문자열, 검사해야하는 M개의 문자열
	std::cin >> N >> M;

	string input;
	int result = 0;
	map<string, bool> set;

	for(int i = 0; i < N; i++)
	{
		std::cin >> input;
		set.insert(pair<string, bool>(input, true));
	}

	for(int i = 0; i < M; i++)
	{
		std::cin >> input;
		if(set[input] == true)
		{
			result += 1;
		}
	}
	std::cout << result << "\n";
	return 0;
}