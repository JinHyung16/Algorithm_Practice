#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	int wordCount(1);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			wordCount += 1;
		}
	}

	if (s[0] == ' ')
	{
		wordCount--;
	}

	if (s[s.length() - 1] == ' ')
	{
		wordCount--;
	}

	cout << wordCount << "\n";
	return 0;
}