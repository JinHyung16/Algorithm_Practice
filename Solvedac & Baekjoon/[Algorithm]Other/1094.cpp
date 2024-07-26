#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver5 막대기 - 수학 알고리즘
/// 23 -> 4
/// 32 -> 1
/// 
/// 23 = 16 + 4 + 2 + 1
/// 32 = 32
/// 48 = 32 + 16
/// 
/// 이진수 합들로 구성이 가능하다.
/// 23기준 
/// 각 필요 숫자를 이진수로 놓고 보면 1에 개수 == 막대 개수
/// 16  = 0001 0000
/// 4   = 0000 0100
/// 2   = 0000 0010
/// 1   = 0000 0001
/// </summary>

int main(void)
{
    FastIO;

    vector<int> stickVec;
    stickVec.push_back(64);

    int x = 0; // 길이가 x인 막대 만들기
    cin >> x;

    int needStickCnt = 0;
    while (0 < x)
    {
        if (x % 2 == 1)
            needStickCnt++;
        x /= 2;
    }

    cout << needStickCnt << "\n";
    return 0;
}