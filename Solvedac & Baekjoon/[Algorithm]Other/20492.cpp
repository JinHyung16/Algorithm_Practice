#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 세금 - 구현 알고리즘
/// 이 문제의 경우 double type으로 출력하면
/// 지수 형태로 출력된다. ex) 7.8e+06 etc..
/// 소수점이 필요 없는 문제로 int type으로 출력하면 된다.
/// </summary>


int main(void)
{
    FastIO;
    
    int N = 0; // 상금 금액 N
    cin >> N;

    int answer1 = N * 0.78;
    int answer2 = N - ((N * 0.2) * 0.22);

    cout << answer1 << " " << answer2 << "\n";
    return 0;
}