#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftHand = 10, leftDis = 0; // *�� 10�� ��ü
    int rightHand = 12, rightDis = 0; // #�� 12�� ��ü
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
        else // 2, 5, 8, 0 �� �ϳ� ���� ���
        {
            if (numbers[i] == 0) // 0�� 11�� ��ü
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
            else // rightDis < leftDis�� ���
            {
                answer += "R";
                rightHand = numbers[i];
            }
        }
    }
    return answer;
}