#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 과자 - 수학 알고리즘
/// </summary>


int main(void)
{
    FastIO;

    int K = 0, N = 0, M = 0; // 과자 한개의 가격 K, 과자의 개수 N, 가진 돈 M
    cin >> K >> N >> M;

    int result = (K * N) - M;

    if (0 < result)
        cout << result << "\n";
    else
        cout << "0" << "\n";

    return 0;
}