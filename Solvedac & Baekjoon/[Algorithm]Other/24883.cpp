#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 자동완성 - 구현 알고리즘
/// n과 N일 if문으로 구별한다
/// </summary>


int main(void)
{
    FastIO;

    char c;
    cin >> c;

    if (c == 'N' || c == 'n')
        cout << "Naver D2" << "\n";
    else
        cout << "Naver Whale" << "\n";
    return 0;
}