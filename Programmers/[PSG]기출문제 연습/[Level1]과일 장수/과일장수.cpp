#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> scoreVec;

    sort(score.rbegin(), score.rend());

    scoreVec = score;

    int index = 0;
    while (true)
    {
        if (scoreVec.size() < index || scoreVec.size() < index + m)
        {
            break;
        }

        answer += scoreVec[index + m - 1] * m;
        index += m;
    }

    return answer;
}