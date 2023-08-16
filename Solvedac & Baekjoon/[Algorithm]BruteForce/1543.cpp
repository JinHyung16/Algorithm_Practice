#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 문서 검색 - 브루트포스 알고리즘
/// 문제에 뒤에 공백까지 포함해야 하므로 getline으로 입력받는다.
/// 전체 주어진 문자열에 대해 비교할 단어를 비교하면서 만약 다른게 나오면 break걸고 bool type을 바꾼다.
/// 그 후 단어를 카운팅하고, break해서 나온 곳 부터 전체 문자열을 비교하도록 index를 바꾼다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string input;
	string word;
	getline(cin, input);
	getline(cin, word);
	int duplicationCnt = 0;

	for ( int i = 0; i < input.size(); i++ )
	{
		bool isCheck = true;
		for ( int j = 0; j < word.size(); j++ )
		{
			if ( input[i + j] != word[j] )
			{
				isCheck = false;
				break;
			}
		}

		if ( isCheck )
		{
			duplicationCnt++;
			i += word.size() - 1;
		}
	}
	std::cout << duplicationCnt << "\n";
	return 0;
}