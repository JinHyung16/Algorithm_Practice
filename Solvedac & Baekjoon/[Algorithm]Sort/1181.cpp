#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver5 단어 정렬 - 문자열, 정렬 알고리즘
/// </summary>

bool SortWordCondition(const string& a, const string& b)
{
	if (a.length() == b.length())
	{
		//같은 길이면 알파벳 순
		return a < b;
	}
	return a.length() < b.length();
}

int main(void)
{
	int input_count = 0;
	string word;
	vector<string> word_list;

	cin >> input_count;
	for (int i = 0; i < input_count; i++)
	{
		cin >> word;
		if (find(word_list.begin(), word_list.end(), word) == word_list.end())
		{
			//find 함수는 중복된게 없으면 last값 반환, 있다면 first값 반환
			word_list.push_back(word);
		}
		word.clear();
	}

	//sort 방법 1)
	sort(word_list.begin(), word_list.end(), SortWordCondition);

	/*
	//sort 방법 2)
	//사전 순으로 sort
	sort(word_list.begin(), word_list.end());
	//길이가 짧은 순서대로 sort
	sort(word_list.begin(), word_list.end(), [](std::string a, std::string b) { return a.size() < b.size(); });
	*/

	for (int i = 0; i < word_list.size(); i++)
	{
		cout << word_list[i] << "\n";
	}

	return 0;
}