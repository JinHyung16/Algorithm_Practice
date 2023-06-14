#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 두 용액 - 정렬 알고리즘
/// 용액을 vector에 담아두고 오름차순 정렬한다.
/// start는 0번째 index를 end는 N-1로 vector의 맨 끝 index를 향하게 설정하고 반복문을 돌린다.
/// minSum = INF, sum = vector[start]+vector[end]를 넣어두고 
/// minSum과 abs(sum) 값을 비교하여 minSum값을 가장 작은 abs(sum)으로 바꿔가며 비교한다.
/// 이때 minSum은 2000000000이여야 한다. 왜냐면 양수 최대가 1000000000이므로 두 수 더하면 2000000000
/// 
/// 1) abs(sum) < minSum이면 minSum을 교체하고 만약 여기서 sum == 0이면, 반복문을 나간다.
/// 2) sum < 0이면, start를 1 증가시켜 음수 값을 바꾼다.
/// 3) sum > 0이면, end값을 1 감소시켜 양수 값을 바꾼다.
/// </summary>

using namespace std;

int main(void)
{
    FastIO;

    int N = 0; //전체 용액의 수 N
    vector<int> solutions;

    std::cin >> N;
    solutions.resize(N, 0);

    for(int i = 0; i < N; i++)
    {
        std::cin >> solutions[i];
    }
    std::sort(solutions.begin(), solutions.end());

    int start = 0, end = N - 1;
    int minSum = 2000000000; //양수 최대가 100000000이므로 이거 두개 더한값으로 설정해둔다.

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