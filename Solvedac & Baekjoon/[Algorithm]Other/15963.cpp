#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 CASIO - 구현 알고리즘
/// 입력으로 들어온 배터리가 같으면 1이고 아니면 0을 출력하면된다.
/// </summary>


int main(void)
{
    FastIO;

    long long N = 0, M = 0; // 송찬이가 필요한 배터리 N, 선생님이 가져온 배터리 M
    cin >> N >> M;

    if (N == M)
        cout << "1" << "\n";
    else
        cout << "0" << "\n";
    return 0;
}