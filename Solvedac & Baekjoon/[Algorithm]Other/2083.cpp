#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 럭비 클럽 - 구현 알고리즘
/// string, int를 이용해 입력받는다.
/// 문제에서 ~거나라고 말한 조건은 or을 의미한다.
/// </summary>


int main(void)
{
	FastIO;

	string name; // 이름
	int age = 0, weight = 0; // 나이와 몸무게
	while ( true )
	{
		cin >> name >> age >> weight;
		if ( name == "#" && age == 0 && weight == 0 )
			return 0;

		if ( 17 < age || 80 <= weight )
			cout << name << " " << "Senior" << "\n";
		else
			cout << name << " " << "Junior" << "\n";
	}
	return 0;
}