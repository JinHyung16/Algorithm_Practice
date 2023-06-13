#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 �� ���� �� - ���� �˰���
/// vector�� ���� �Է¹޾� �������� �����صд�.
/// start�� vector�� 0��° index��, end�� vector�� ������ index�� ���ϰ� �����صд�.
/// �� �� while (start < end)�� ���鼭
/// 1) vecotr[start] + vector[end]�� == x, ī�����ϰ� start���� end ����
/// 2) vector[start] + vector[end]�� < x �� start ����
/// 3) vector[start] + vector[end]�� > x �� end ����
/// �̸� �ݺ��Ͽ� ī������ ���� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
    FastIO;

    int n = 0, x = 0; //n���� ���δٸ� ���, ���� x�� �Ǵ� ��
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