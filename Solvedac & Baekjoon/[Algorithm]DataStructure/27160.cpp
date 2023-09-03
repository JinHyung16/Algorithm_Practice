#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 할리갈리 - 자료구조 알고리즘
/// map을 이용해 해당 string을 key값으로 value 즉 입력받은 개수만큼 증가시킨다.
/// 그 후 5개인게 하나라도 있다면 YES를 아니면 NO를 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //펼쳐진 카드의 개수 N
	std::cin >> N;

	map<string, int> fruit;
	
	for ( int i = 0; i < N; i++ )
	{
		//과일 종류를 나타내는 문자열 S와 과일의 개수 양의 정수 X
		string S = " ";
		int X = 0;
		std::cin >> S >> X;
		fruit[S] += X;
	}

	if ( fruit["STRAWBERRY"] == 5 || fruit["BANANA"] == 5 || fruit["LIME"] == 5 || fruit["PLUM"] == 5 )
	{
		std::cout << "YES" << "\n";
		return 0;
	}

	std::cout << "NO" << "\n";
	return 0;
}