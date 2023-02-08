#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 알파벳 개수 - 문자열 알고리즘
/// 미리 해당 알파벳 개수를 담는 배열 alphabet선언하고
/// 입력받은 string-97을 alphabet[string[i]-97]++해서
/// 바로바로 해당 알파벳의 개수를 증가시켜준다.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	
	vector<int> alphabet(26, 0);
	string input;
	std::cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		alphabet[input[i] - 97]++;
	}

	//소문자 알파벳의 개수가 26개니깐
	for (int i = 0; i < 26; i++)
	{
		std::cout << alphabet[i] << " ";
	}
	return 0;
}