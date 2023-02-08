#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 ���ĺ� ���� - ���ڿ� �˰���
/// �̸� �ش� ���ĺ� ������ ��� �迭 alphabet�����ϰ�
/// �Է¹��� string-97�� alphabet[string[i]-97]++�ؼ�
/// �ٷιٷ� �ش� ���ĺ��� ������ ���������ش�.
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

	//�ҹ��� ���ĺ��� ������ 26���ϱ�
	for (int i = 0; i < 26; i++)
	{
		std::cout << alphabet[i] << " ";
	}
	return 0;
}