#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 상근날드 - 수학 알고리즘
/// 버거와 음료 가격들을 다 더해 vector에 넣는다.
/// 그 후 정렬을 통해 맨 앞에 값을 출력한다.
/// </summary>


int main(void)
{
    FastIO;

    int buger = 2001, drink = 2001;

    for (int i = 0; i < 5; i++)
    {
        int input = 0;
        cin >> input;

        if (i < 3)
            buger = min(input, buger);
        else
            drink = min(input, drink);
    }

    cout << (buger + drink - 50) << "\n";
    return 0;
}