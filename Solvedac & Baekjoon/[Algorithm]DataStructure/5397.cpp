#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver2 키로거 - 자료구조 알고리즘
/// 문제에서 연결 리스트를 사용하면 쉽다하여 힌트를 얻었습니다.
/// c++의 list는 정렬, merge, splice(이어 붙이기)가 가능하다
/// list는 ++, --로 양방향 탐색을 한다.
/// </summary>


int main(void)
{
    FastIO;

    int T = 0; // 테스트 케이스
    cin >> T;

    list<char> password;
    list<char>::iterator cursor;
    while (T--)
    {
        string input;
        cin >> input;

        password.clear();
        cursor = password.begin();

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '<')
            {
                if (cursor != password.begin())
                    cursor--;
            }
            else if (input[i] == '>')
            {
                if (cursor != password.end())
                    cursor++;
            }
            else if (input[i] == '-')
            {
                if (cursor != password.begin())
                    cursor = password.erase(--cursor);
            }
            else
            {
                cursor = password.insert(cursor, input[i]);
                cursor++;
            }
        }

        for (char c : password)
            cout << c;
        cout << "\n";
    }
    return 0;
}