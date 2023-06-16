#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold2 보석 도둑 - 정렬 알고리즘
/// 보석의 경우 vector<pair>에 (보석 무게, 가격)을 넣고 무게 순으로 오름차순한다.
/// 가방의 경우 vector<int>로 (가방 용량)을 넣고 용량 순으로 오름차순 한다.
/// priority_queue<int>에는 가방에 담긴 보석들의 최댓 값을 정렬해둔다.
/// 
/// 2중 for문을 통해 for i to K에 대해 for j to N을 실행하는데 이때 주의한다.
/// 보석을 가방에 넣었으면, 이미 넣은 보석은 더이상 가방에 넣을 수 없으므로 보석에 대한 index는 가장 바깥쪽에 선언해둔다.
/// 보석을 넣을 수 있으면 넣고, 없으면 break하여 나온다.
/// 그 후 pq에 값이 있다면 해당 값을 꺼내 result 변수에 쌓아두고, pop시켜서 가방 개수만큼 이를 반복한다.
/// 
/// 만약 이렇게 하지 않을경우에 대한 반례)
/// 3 3
/// 20 12
/// 0 20
/// 16 16
/// 17
/// 14
/// 7
/// 에 대하여 결과가 36이 정답인데, 20이 나온다.
/// </summary>

using namespace std;

int main(void)
{
    FastIO;
    
    int N = 0, K = 0; //보석 N개, 가방 K개
    int M = 0, V = 0; //보석의 무게 M, 가격 V
    int C = 0; //가방 최대 용량 C
    
    vector<pair<int,int>> diamonds;
    vector<int> bags;
    priority_queue<int> pq;

    std::cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        std::cin >> M >> V;
        diamonds.push_back(make_pair(M, V));
    }

    for(int i = 0; i < K; i++)
    {
        std::cin >> C;
        bags.push_back(C);
    }

    std::sort(diamonds.begin(), diamonds.end());
    std::sort(bags.begin(), bags.end());
    
    long long result = 0;
    int jewelIndex = 0;
    for(int i = 0; i < K; i++)
    {
        for( ; jewelIndex < N; jewelIndex++)
        {
            if( diamonds[jewelIndex].first <= bags[i])
            {
                pq.push(diamonds[jewelIndex].second);
            }
            else
            {
                break;
            }
        }

        if(!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
    }

    std::cout << result << "\n";
    return 0;
}