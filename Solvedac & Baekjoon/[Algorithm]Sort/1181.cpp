#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver5 �ܾ� ���� - ���ڿ�, ���� �˰���
/// </summary>

bool SortWordCondition(const string& a, const string& b)
{
	if (a.length() == b.length())
	{
		//���� ���̸� ���ĺ� ��
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
			//find �Լ��� �ߺ��Ȱ� ������ last�� ��ȯ, �ִٸ� first�� ��ȯ
			word_list.push_back(word);
		}
		word.clear();
	}

	//sort ��� 1)
	sort(word_list.begin(), word_list.end(), SortWordCondition);

	/*
	//sort ��� 2)
	//���� ������ sort
	sort(word_list.begin(), word_list.end());
	//���̰� ª�� ������� sort
	sort(word_list.begin(), word_list.end(), [](std::string a, std::string b) { return a.size() < b.size(); });
	*/

	for (int i = 0; i < word_list.size(); i++)
	{
		cout << word_list[i] << "\n";
	}

	return 0;
}