#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���� ����� �� ����� �ɸ��� �Ÿ� - ���Ʈ���� �˰���
/// ��ѱ��� ������ �����ϸ�, �� ����� �ɸ��� �Ÿ� �� min���� ã�°ǵ�
/// ��ѱ��� ������ �����غ��� ��ѱ����� mbti ���� 16�̰�, ��ѱ�� ����� N�̴�.
/// N�� 17���� �� mbti�� �ߺ��� �� ����� ���� �� �ִ°� Ȯ���̴�. �̿� N�� 32�� �Ѵ¼�����
/// �ƹ��� �ɸ��� �Ÿ��� �ָ� �Ϸ��� mbti�� �Է��ص� �ݵ�� mbti �Ѱ��� 3���� ����� �ߺ��Ǵ� ��찡 �����.
/// ���� N�� 32�� ������ ������ �Ÿ��� 0�̰�, �ƴ� ��츸 ����Ѵ�.
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

    int T = 0; //�׽�Ʈ ���̽� �� T
    int N(0); //�л��� �� N

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