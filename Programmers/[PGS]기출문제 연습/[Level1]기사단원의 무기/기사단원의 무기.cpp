#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> measure(number + 1, 0);

    //1부터 n까지의 약수 개수 저장하는 방식 기억하기
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= (number / i); j++)
        {
            measure[i * j]++;
        }
    }

    for (int i = 1; i <= number; i++)
    {
        if (measure[i] > limit)
        {
            measure[i] = power;
        }
    }

    for (int i = 1; i <= number; i++)
    {
        answer += measure[i];
    }
    return answer;
}