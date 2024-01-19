#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 타임 카드 - 구현 알고리즘
/// 시 분 초를 입력받아 계산하는 대신 모두 초로 바꿔서
/// 시작 초와 끝나는 초의 차이를 구하고 이를 다시 시 분 초로 분배한다.
/// 시는 3600초, 분은 60초임을 이용한다.
/// </summary>


int main(void)
{
	FastIO;

	int h1 = 0, m1 = 0, s1 = 0; // 출근 시 분 초
	int h2 = 0, m2 = 0, s2 = 0; // 퇴근 시 분 초
	for ( int i = 0; i < 3; i++ )
	{
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

		int start = (h1 * 3600) + (m1 * 60) + s1;
		int end = (h2 * 3600) + (m2 * 60) + s2;

		int resultH = (end - start) / 3600;
		int resultM = ((end - start) % 3600) / 60;
		int resultS = ((end - start) % 3600) % 60;

		cout << resultH << " " << resultM << " " << resultS << "\n";
	}

	return 0;
}