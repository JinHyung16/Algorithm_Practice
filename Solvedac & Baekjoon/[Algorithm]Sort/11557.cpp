#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze1 Yangjojang of The Year - 정렬 알고리즘
/// </summary>

int main(void)
{
    FastIO;
    
    int T = 0, N = 0; // 테스트 케이스 T, 학교수 N
    string S; // 학교 이름 S
    int L = 0; // S가 소비한 술의 양 L

    vector<pair<int, string>> school;

    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> S >> L;
            school.push_back(make_pair(L, S));
        }
        sort(school.rbegin(), school.rend());
        cout << school.front().second << "\n";
        school.clear();
    }
    return 0;
}