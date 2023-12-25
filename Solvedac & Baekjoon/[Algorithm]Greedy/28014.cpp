#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze3 첨탑 밀어서 부수기 - Greedy 알고리즘
/// 첨탑을 밀 수 있을때 첨탑의 위치 (배열의 index)를 증가시킨다.
/// 이렇게 해야 첨탑을 미는 행위땐 pushCnt가 증가하면서 첨탑 위치가 변한다.
/// </summary>

int main(void)
{
    FastIO;
    
    int N = 0;
    cin >> N;
    vector<int> topVec(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> topVec[i];
    }

    int pushCnt = 0;
    for (int i = 0; i < N; i++) {
        while (i < N - 1 && topVec[i + 1] < topVec[i])
            i++;
        pushCnt++;
    }

    cout << pushCnt << "\n";
    return 0;
}