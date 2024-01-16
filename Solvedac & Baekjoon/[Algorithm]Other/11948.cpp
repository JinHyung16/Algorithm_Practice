#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 과목선택 - 수학 알고리즘
/// </summary>


int main(void)
{
    FastIO;

    int a[4] = { 0, };
    int b[2] = { 0, };

    int input = 0, sum = 0;
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    for (int i = 0; i < 2; i++)
        cin >> b[i];

    sort(a, a + 4);
    sort(b, b + 2);

    cout << (a[3] + a[2] + a[1] + b[1]) << "\n";

    return 0;
}