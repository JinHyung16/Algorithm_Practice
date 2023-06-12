#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 가장 가까운 세 사람의 심리적 거리 - 브루트포스 알고리즘
/// 비둘기집 원리를 생각하면, 세 사람의 심리적 거리 중 min값을 찾는건데
/// 비둘기집 원리를 생각해보면 비둘기집이 mbti 개수 16이고, 비둘기는 사람인 N이다.
/// N이 17부턴 한 mbti에 중복인 두 사람이 있을 수 있는게 확정이다. 이에 N이 32를 넘는순간엔
/// 아무리 심리적 거리를 멀리 하려고 mbti를 입력해도 반드시 mbti 한곳에 3명의 사람이 중복되는 경우가 생긴다.
/// 따라서 N이 32를 넘으면 무조건 거리는 0이고, 아닌 경우만 계산한다.
/// </summary>

using namespace std;

int MBTI_Distance(string a, string b)
{
    int mbtiDis = 0;
    for(int i = 0; i < 4; i++)
    {
        if(a[i] != b[i])
        {
            mbtiDis ++;
        }
    }

    return mbtiDis;
}

int main(void)
{
    FastIO;

    int T = 0; //테스트 케이스 수 T
    int N(0); //학생의 수 N

    string mbti = ""; //mbti
    vector<string> mbtiVec;

    int disMin = 987654321;
    int tempMin = 0;

    std::cin >> T;
    while(T--)
    {
        std::cin >> N;

        tempMin = 0;
        disMin = 987654321;
        mbtiVec.clear();

        for(int i = 0; i < N; i++)
        {
            std::cin >> mbti;
            mbtiVec.push_back(mbti);		
        }

        if(32 < N)
        {
            disMin = 0;
        }
        else
        {
            for ( int i = 0; i < N - 2; i++ )
            {
                for ( int j = i + 1; j < N - 1; j++ )
                {
                    for ( int k = j + 1; k < N; k++ )
                    {
                        disMin = std::min(disMin, MBTI_Distance(mbtiVec[i], mbtiVec[j]) + MBTI_Distance(mbtiVec[i], mbtiVec[k]) + MBTI_Distance(mbtiVec[j], mbtiVec[k]));
                    }
                }
            }
        }
        std::cout << disMin << "\n";
    }
    return 0;
}