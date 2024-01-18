#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 베라의 패션 - 수학 알고리즘
/// 경우의 수로 중복을 제외해서 뽑아야 하므로
/// 상의 N이면 하의는 N-1개를 뽑으니 곱하면된다.
/// </summary>


int main(void)
{
    FastIO;

    int N = 0; // 상의 N벌과 하의 N벌
    cin >> N;

    cout << N * (N - 1) << "\n";
    return 0;
}