#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 캠핑 - Greedy 알고리즘
/// ex) L=5, P=8, V=20인경우
/// 최대 5일 + 남는 3일 + 최대 5일 + 남는 3일 + 남은 일수(20 - (5+3+5+3) = 4일) = 20일
/// 이때 남은 일수가 L보다 크다면 남은 일수를 L로 변경
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int L = 0, P = 0, V = 0; //연속하는 P일 중, L일동안만 사용 가능. V일짜리 휴가 시작
	int testCaseNum = 1;
	while ( true )
	{
		std::cin >> L >> P >> V;
		if ( L == 0 && P == 0 && V == 0 ) break;
		int use = V / P;
		int remain = V % P;
		if ( L < remain )
		{
			remain = L;
		}
		int result = L * use + remain;
		std::cout << "Case " << testCaseNum << ": " << result << "\n";
		testCaseNum++;
	}
	return 0;
}