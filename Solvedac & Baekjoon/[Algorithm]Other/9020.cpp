#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver2 골드바흐의 추측 - 수학 알고리즘
/// 에라토스테네스의 체를 이용해 소수가 아닌건 false로 한다.
/// 그 후 주어진 n에서 n/2부터 시작하여 하나씩 감소하면서
/// prime[i]와 prime[n-i]가 true인 경우 출력한다.
/// </summary>

int MAX_INT = 10000;

vector<bool> prime(MAX_INT + 1, true);

void Eratosthenes()
{
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= MAX_INT; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= MAX_INT; j += i)
                prime[j] = false;
        }
    }
}

int main(void)
{
    FastIO;

    int T = 0; // 테스트 케이스 T
    int n = 0; // n의 골드바흐

    Eratosthenes();

    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = n / 2; 1 < i; i--)
        {
            if (prime[i] && prime[n - i])
            {
                cout << i << " " << n - i << "\n";
                break;
            }
        }
    }
    return 0;
}