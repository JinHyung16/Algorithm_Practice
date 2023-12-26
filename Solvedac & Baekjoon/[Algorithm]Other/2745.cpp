#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze2 진법 변환 - 문자열 알고리즘
/// pow()를 사용하면 79152(5)는 10진법 변환시 5552가 나와야 하나 5551이 나온다.
/// 이는 pow()가 부동소수점 연산을 수행해 정확한 정수 연사을 보장하지 않은 경우가 생기기 때문이다.
/// </summary>

int main(void)
{
    FastIO;

    string N; // N진법
    int B = 0; // N진법 수 B
    cin >> N >> B;

    int result = 0;
    for (int i = 0; i < N.length(); i++)
    {
        if ('0' <= N[i] && N[i] <= '9')
            result = result * B + (N[i] - '0');
        else
            result = result * B + (N[i] - 'A' + 10);
    }

    cout << result << "\n";
    return 0;
}