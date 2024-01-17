#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 상근이의 친구들 - 수학 알고리즘
/// </summary>


int main(void)
{
    FastIO;

    int a = 0, b = 0;

    while (true)
    {
        cin >> a >> b;

        if (a == 0 && b == 0)
            return 0;

        cout << (a + b) << "\n";
    }
    return 0;
}