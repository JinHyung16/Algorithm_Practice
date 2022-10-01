#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftHand = 10, leftDis = 0; // *은 10로 대체
    int rightHand = 12, rightDis = 0; // #은 12로 대체
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            leftHand = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += "R";
            rightHand = numbers[i];
        }
        else // 2, 5, 8, 0 중 하나 누른 경우
        {
            if (numbers[i] == 0) // 0은 11로 대체
            {
                numbers[i] = 11;
            }

            int l_dis = abs(leftHand - numbers[i]);
            int r_dis = abs(rightHand - numbers[i]);

            leftDis = (l_dis / 3) + (l_dis % 3);
            rightDis = (r_dis / 3) + (r_dis % 3);

            if (leftDis == rightDis)
            {
                if (hand == "right")
                {
                    answer += "R";
                    rightHand = numbers[i];
                }
                else
                {
                    answer += "L";
                    leftHand = numbers[i];
                }
            }
            else if (leftDis < rightDis)
            {
                answer += "L";
                leftHand = numbers[i];
            }
            else // rightDis < leftDis의 경우
            {
                answer += "R";
                rightHand = numbers[i];
            }
        }
    }
    return answer;
}