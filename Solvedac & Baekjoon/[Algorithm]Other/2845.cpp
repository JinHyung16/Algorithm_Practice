#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 파티가 끝나고 난 뒤 - 수학 알고리즘
/// L*P를 진행한 후 신문사마다 파티 참여자 수에서 이 값을 뺀다.
/// </summary>


int main(void)
{
    FastIO;

    int L = 0, P = 0; // 사람의 수 L, 파티 장소의 넓이 P
    cin >> L >> P;

    int partyDiffer[5] = {0, };
    for (int i = 0; i < 5; i++)
    {
        int joinPeople = 0;
        cin >> joinPeople;
        partyDiffer[i] = joinPeople - (L * P);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << partyDiffer[i] << " ";
    }
    cout << "\n";

    return 0;
}