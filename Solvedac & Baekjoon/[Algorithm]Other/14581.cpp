#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 팬들에게 둘러싸인 홍준 - 구현 알고리즘
/// 입력으로 들어온것을 가운데 배치하고 나머진 문제에 맞춰 출력한다.
/// </summary>


int main(void)
{
    FastIO;
    string input;
    cin >> input;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                cout << ":" << input << ":";
            else
                cout << ":fan:";
        }
        cout << "\n";
    }
    return 0;
}