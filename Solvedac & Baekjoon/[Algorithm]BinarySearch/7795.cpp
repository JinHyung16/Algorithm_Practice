#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver3 먹을 것인가 먹힐 것인가 - 이분 탐색 알고리즘
/// 이분 탐색을 진행하기전 다 채운 두 배열을 오름차순으로 정렬해둔다.
/// 그 후 문제 조건에 맞춰 해결한다. 
/// </summary>

int BinarySearch(vector<int>& a, vector<int>& b)
{
    int answer = 0;

    for (int i = 0; i < a.size(); i++)
    {
        int left = 0, right = b.size();
        while (left + 1 < right)
        {
            int mid = (left + right) / 2;
            if (b[mid] < a[i])
                left = mid;
            else
                right = mid;
        }
        answer += left;
        if (b[left] < a[i])
            answer++;
    }
    return answer;
}

int main(void)
{
    FastIO;
    
    int T = 0; // 테스트 케이스 T
    int N = 0, M = 0; // A의 수 N, B의 수 M
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        vector<int> A(N, 0), B(M, 0);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < M; i++)
        {
            cin >> B[i];
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int result = BinarySearch(A, B);
        cout << result << "\n";
    }
    return 0;
}