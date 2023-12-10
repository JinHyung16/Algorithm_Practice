#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze2 분산처리 - 구현 알고리즘
/// pow 함수를 사용하면 시간 초과가 뜬다.
/// 문제 조건을 보면 우리는 1의 자리만 알면 된다.
/// 일의 자리 기준으로 0 = 10, 1 = 11, 2 = 12 ... 9 = 19 이렇게 10단위씩 증가
/// </summary>

int main(void)
{
	FastIO;

	int T = 0; // 테스트 케이스 T
	int a = 0, b = 0; // 데이터 개수 a^b개
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		int temp = 1;
		for (int i = 0; i < b; i++)
		{
			temp = (temp * a) % 10;
		}

		if (temp == 0)
			cout << 10 << "\n";
		else
			cout << temp << "\n";
	}
	return 0;
}