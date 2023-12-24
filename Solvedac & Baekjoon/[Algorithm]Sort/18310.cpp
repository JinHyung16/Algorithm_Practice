#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver3 안테나 - Greedy 알고리즘
/// 집 위치를 입력 받은 다음 오름차순 정렬한다.
/// 그 후 (N-1)/2 번째 집의 설치하면 평균으로 최소가 된다.
/// </summary>

int main(void)
{
    FastIO;

    int N = 0; // 집의 수 N
    cin >> N;

    vector<int> house(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> house[i];
    }
    sort(house.begin(), house.end());
    int result = house[(N - 1) / 2];

    cout << result << "\n";

    return 0;
}