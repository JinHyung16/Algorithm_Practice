#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 몇개고? - 구현 알고리즘
/// 문제의 조건을 잘 읽고 || 나 &&를 활용한다.
/// </summary>


int main(void)
{
    FastIO;
    
    int T = 0, S = 0; // 시간 T, 술 유무 S

    cin >> T >> S;
    if (12 <= T && T <= 16 && S == 0) 
    {
        cout << "320" << "\n";
    }
    else if( S == 1 || T <= 11 || 16 <= T)
    {
        cout << "280" << "\n";
    }
    return 0;
}