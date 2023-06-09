#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ���̻� �迭 - ���� �˰���
/// 1) ���ڿ� S�� ������, �ش� ���̸�ŭ vector<string>�� �����.
/// 2) S.substr(i, S.size())�� ���� ���ڿ��� i���� �� ������ ������ ���� vector�� �ִ´�.
/// 3) vector�� �� index�� ���ڿ��� ������ sort�Ѵ�.
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