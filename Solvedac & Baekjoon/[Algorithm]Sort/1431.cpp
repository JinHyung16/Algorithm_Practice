#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver3 시리얼 번호 - 정렬 알고리즘
/// Sort함수를 이용하면서 마지막 인자값의 직접 만든 비교 연산을 넣는다.
/// </summary>


bool CompareSerial(string a, string b)
{
	if (a.size() != b.size()) return a.size() < b.size();
	else
	{
		int asum = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i] - '0' <= 9 && a[i] - '0' >= 0)
				asum += a[i] - '0';
		}

		int bsum = 0;
		for (int i = 0; i < b.size(); ++i)
		{
			if (b[i] - '0' <= 9 && b[i] - '0' >= 0)
				bsum += b[i] - '0';
		}

		if (asum != bsum)
			return asum < bsum;
		else 
			return a < b; // 알파벳 순서대로
	}
}

int main(void)
{
    FastIO;
    
    int N = 0; // 기타의 개수 N
    cin >> N;
    vector<string> serialVec;
    string serial;
    for (int i = 0; i < N; i++)
    {
        cin >> serial;
        serialVec.push_back(serial);
    }

    sort(serialVec.begin(), serialVec.end(), CompareSerial);

    for (int i = 0; i < serialVec.size(); i++)
    {
        cout << serialVec[i] << "\n";
    }


    return 0;
}