#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 파티가 끝나고 난 뒤 - 수학 알고리즘
/// </summary>


int main(void)
{
    FastIO;

    int a = 0, b = 0, c = 0, d = 0;
    
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < 2; i++)
    {
        cin >> a >> b >> c >> d;
        if (i == 0)
            sum1 = (a + b + c + d);
        else
            sum2 = (a + b + c + d);
    }

    int answer = max(sum1, sum2);
    cout << answer << "\n";
    return 0;
}