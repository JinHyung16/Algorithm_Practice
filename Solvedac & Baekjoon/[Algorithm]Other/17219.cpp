#include<iostream>
#include<vector>
#include<map>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 비밀번호 찾기 - 자료구조 알고리즘
/// 중복을 허용하지 않는 (key,value) 쌍으로 이뤄진 트리 map을 이용했다.
/// c++ map은 검색, 삽입, 삭제가 O(logN)이다. 기본적으로 오름차순 정렬이다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0), M(0); //저장된 사이트 주소의 수 N, 비밀번호를 찾으려는 사이트 주소의 수 M
	map<string, string> memoNote;
	std::cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		string site, password;
		std::cin >> site >> password;
		memoNote.insert(make_pair(site, password));
	}

	for (int i = 0; i < M; i++)
	{
		string findSite;
		std::cin >> findSite;
		std::cout << memoNote[findSite] << "\n";
	}
	return 0;
}