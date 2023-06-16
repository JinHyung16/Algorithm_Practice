#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold2 ���� ���� - ���� �˰���
/// ������ ��� vector<pair>�� (���� ����, ����)�� �ְ� ���� ������ ���������Ѵ�.
/// ������ ��� vector<int>�� (���� �뷮)�� �ְ� �뷮 ������ �������� �Ѵ�.
/// priority_queue<int>���� ���濡 ��� �������� �ִ� ���� �����صд�.
/// 
/// 2�� for���� ���� for i to K�� ���� for j to N�� �����ϴµ� �̶� �����Ѵ�.
/// ������ ���濡 �־�����, �̹� ���� ������ ���̻� ���濡 ���� �� �����Ƿ� ������ ���� index�� ���� �ٱ��ʿ� �����صд�.
/// ������ ���� �� ������ �ְ�, ������ break�Ͽ� ���´�.
/// �� �� pq�� ���� �ִٸ� �ش� ���� ���� result ������ �׾Ƶΰ�, pop���Ѽ� ���� ������ŭ �̸� �ݺ��Ѵ�.
/// 
/// ���� �̷��� ���� ������쿡 ���� �ݷ�)
/// 3 3
/// 20 12
/// 0 20
/// 16 16
/// 17
/// 14
/// 7
/// �� ���Ͽ� ����� 36�� �����ε�, 20�� ���´�.
/// </summary>

using namespace std;

int main(void)
{
    FastIO;
    
    int N = 0, K = 0; //���� N��, ���� K��
    int M = 0, V = 0; //������ ���� M, ���� V
    int C = 0; //���� �ִ� �뷮 C
    
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