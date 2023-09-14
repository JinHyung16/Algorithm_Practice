#include<iostream>
#include<vector>
#include<set>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 대칭 차집합 - 자료 구조 알고리즘
/// set은 자동으로 오름차순 정렬된다.
/// 그러므로 A를 입력받고, B를 입력받을 떄 
/// if ( result.find(input) == result.end() )는 set은 값이 없으면 end를 반환하므로
/// 만약 없다면 넣으라는 의미다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int A = 0, B = 0; 
	int input = 0;
	std::cin >> A >> B;

	set<int> result;
	for ( int i = 0; i < A; i++ )
	{
		std::cin >> input;
		result.insert(input);
	}

	for ( int i = 0; i < B; i++ )
	{
		std::cin >> input;
		if ( result.find(input) == result.end() )
		{
			result.insert(input);
		}
		else
		{
			result.erase(input);
		}
	}

	std::cout << result.size() << "\n";
	return 0;
}