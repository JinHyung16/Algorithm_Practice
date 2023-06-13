#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 두 수의 합 - 정렬 알고리즘
/// vector에 수를 입력받아 오름차순 정렬해둔다.
/// start는 vector의 0번째 index를, end는 vector의 마지막 index를 향하게 설정해둔다.
/// 그 후 while (start < end)를 돌면서
/// 1) vecotr[start] + vector[end]값 == x, 카운팅하고 start증가 end 감소
/// 2) vector[start] + vector[end]값 < x 면 start 증가
/// 3) vector[start] + vector[end]값 > x 면 end 감소
/// 이를 반복하여 카운팅한 수를 출력한다.
/// </summary>

using namespace std;

int main(void)
{
    FastIO;

    int n = 0, x = 0; //n개의 서로다른 양수, 합이 x가 되는 수
    vector<int> sequence;

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a = 0;
        std::cin >> a;
        sequence.push_back(a);
    }
    std::cin >> x;

    std::sort(sequence.begin(), sequence.end());
    int start = 0;
    int end = sequence.size() - 1;
    int sum = 0;
    int result = 0;
    while(start < end)
    {
        sum = sequence[start] + sequence[end];
        if(sum == x)
        {
            result ++;
            start ++;
            end --;
        }

        if(sum < x)
        {
            start ++;
        }
        if(x < sum)
        {
            end --;
        }
    }

    std::cout << result << "\n";
    return 0;
}