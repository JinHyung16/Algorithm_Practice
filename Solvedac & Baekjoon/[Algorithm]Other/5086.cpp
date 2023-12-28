#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze3 배수와 약수 - 수학 알고리즘
/// 첫 번째 수가 두 번째 수의 약수면 factor
/// 첫 번째 수가 두 번째 수의 배수면 multiple
/// 첫 번째 수가 두 번째 수의 약수 배수가 모두 아니면 neither
/// </summary>

int main(void)
{
    FastIO;

    int a = 0, b = 0; // 두 수 a,b
    while (true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            return 0;

        if (a % b == 0)
            cout << "multiple" << "\n";
        else if (b % a == 0)
            cout << "factor" << "\n";
        else
            cout << "neither" << "\n";
    }
    return 0;
}