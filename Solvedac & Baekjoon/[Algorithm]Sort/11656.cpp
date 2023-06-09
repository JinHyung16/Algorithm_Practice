#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 접미사 배열 - 정렬 알고리즘
/// 1) 문자열 S를 받으면, 해당 길이만큼 vector<string>을 만든다.
/// 2) S.substr(i, S.size())를 통해 문자열을 i부터 맨 끝가지 제거한 값을 vector에 넣는다.
/// 3) vector의 각 index의 문자열을 가져와 sort한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string input;
	std::cin >> input;
	vector<string> dictionary(input.size(), " ");
	
	for (int i = 0; i < input.size(); i++)
	{
		dictionary[i] = input.substr(i, input.size());
	}

	std::sort(dictionary.begin(), dictionary.end());
	
	for (int i = 0; i < dictionary.size(); i++)
	{
		std::cout << dictionary[i] << "\n";
	}
	return 0;
}