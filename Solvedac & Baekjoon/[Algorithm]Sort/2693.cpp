#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 N번째 큰 수 - 정렬 알고리즘
/// std::sort를 이용하면 log N만에 sort가 된다.
/// 이때 sort(vector.rbegin(), vector.rend()); 는 큰 수부터 내림차순 정렬을 의미한다.
/// 그 후 배열은 0번째부터 시작이니 3번째 큰 수를 출력하려면 index값으로 2를 넣어야한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int T = 0; //테스트 케이스 개수
	std::cin >> T;
	vector<int> sortVec(10, 0);
	while ( T-- )
	{
		for ( int i = 0; i < 10; i++ )
		{
			std::cin >> sortVec[i];
		}
		std::sort(sortVec.rbegin(), sortVec.rend());
		std::cout << sortVec[2] << "\n";
	}
	return 0;
}