#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 �� ��� - ���� �˰���
/// ����� vector�� ��Ƶΰ� �������� �����Ѵ�.
/// start�� 0��° index�� end�� N-1�� vector�� �� �� index�� ���ϰ� �����ϰ� �ݺ����� ������.
/// minSum = INF, sum = vector[start]+vector[end]�� �־�ΰ� 
/// minSum�� abs(sum) ���� ���Ͽ� minSum���� ���� ���� abs(sum)���� �ٲ㰡�� ���Ѵ�.
/// �̶� minSum�� 2000000000�̿��� �Ѵ�. �ֳĸ� ��� �ִ밡 1000000000�̹Ƿ� �� �� ���ϸ� 2000000000
/// 
/// 1) abs(sum) < minSum�̸� minSum�� ��ü�ϰ� ���� ���⼭ sum == 0�̸�, �ݺ����� ������.
/// 2) sum < 0�̸�, start�� 1 �������� ���� ���� �ٲ۴�.
/// 3) sum > 0�̸�, end���� 1 ���ҽ��� ��� ���� �ٲ۴�.
/// </summary>

using namespace std;

int main(void)
{
    FastIO;

    int N = 0; //��ü ����� �� N
    vector<int> solutions;

    std::cin >> N;
    solutions.resize(N, 0);

    for(int i = 0; i < N; i++)
    {
        std::cin >> solutions[i];
    }
    std::sort(solutions.begin(), solutions.end());

    int start = 0, end = N - 1;
    int minSum = 2000000000; //��� �ִ밡 100000000�̹Ƿ� �̰� �ΰ� ���Ѱ����� �����صд�.

    int acidSolution = solutions[start], alkalineSolution = solutions[end];

    while(start < end)
    {
        int sum = solutions[start] + solutions[end];
        if(abs(sum) < minSum)
        {
            minSum = abs(sum);
            acidSolution = solutions[start];
            alkalineSolution = solutions[end];

            if(sum == 0)
            {
                break;
            }
        }

        if(0 < sum)
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    if(alkalineSolution < acidSolution)
    {
        int temp = alkalineSolution;
        alkalineSolution = acidSolution;
        acidSolution = temp;
    }
    std::cout << acidSolution << " " << alkalineSolution << "\n";
    
    return 0;
}