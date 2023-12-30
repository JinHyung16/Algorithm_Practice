#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver3 서로 다른 부분 문자열의 개수 - 자료구조 알고리즘
/// </summary>

int main(void)
{
    FastIO;

    string S; // 문자열 S
    cin >> S;
    
    string temp;
    set<string> subString;

    for (int i = 0; i < S.size(); i++)
    {
        for (int j = i; j < S.size(); j++)
        {
            temp += S[j];
            subString.insert(temp);
        }
        temp = "";
    }
    cout << subString.size() << "\n";

    return 0;
}