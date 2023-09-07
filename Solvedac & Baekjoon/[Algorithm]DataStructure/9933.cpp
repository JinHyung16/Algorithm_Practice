#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 민균이의 비밀번호 - 자료구조 알고리즘
/// 문자를 다 입력받고 나면, i번째와 역순한 j번째를 비교하여 같으면 출력하고 끝낸다.	
/// </summary>

using namespace std;

string GetReverseWord(string input)
{
	string temp = "";
	for ( int i = 0; i < input.size(); i++ )
	{
		temp += input[input.size() - 1 - i];
	}
	return temp;
}

int main(void)
{
	FastIO;

	vector<string> word;
	int N = 0; //단어의 수
	std::cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		string input;
		std::cin >> input;
		word.push_back(input);
	}
	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < N; j++ )
		{
			if ( word[i] == GetReverseWord(word[j]))
			{
				int size = word[i].size();
				std::cout << size << " " << word[i][size / 2];
				return 0;
			}
		}
	}
	
	return 0;
}