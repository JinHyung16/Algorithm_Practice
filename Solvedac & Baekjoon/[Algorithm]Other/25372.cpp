#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 성택이의 은밀한 비밀번호 - 구현 알고리즘
/// 문자열의 length를 찍어 비교한다.
/// </summary>


int main(void)
{
    FastIO;

    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        if (6 <= input.length() && input.length() <= 9)
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }
    return 0;
}