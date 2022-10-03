#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	// alphabat 'a' to 'z' -> total count 26��
	// �󵵼��� �����ϴ� �迭 ����
	// ASCII �ҹ��� 97~122, �빮�� 65~90
	int alphabat[26] = { 0, };
	
	string s_input = "";
	int duplicateCount = 0;

	cin >> s_input;

	for (int i = 0; i < s_input.length(); i++)
	{
		if (s_input[i] < 97)
		{
			// �빮�ڶ��
			alphabat[s_input[i] - 65] ++;
		}
		else
		{
			// �ҹ��ڶ��
			alphabat[s_input[i] - 97] ++;
		}
	}

	int max = 0, max_index = 0;

	// alpahbat ����ŭ �迭 �� ����
	// � ���ĺ��� ���ͼ� ���� ���ߴ��� �𸣱⿡ �� ���Ƽ� üũ�ؾ���
	for (int i = 0; i < 26; i++)
	{
		if (max < alphabat[i])
		{
			max = alphabat[i];
			max_index = i;
		}
	}

	// ���� ���� ���� ���ĺ��� ���������� �˻�
	for (int i = 0; i < 26; i++)
	{
		if (max == alphabat[i])
		{
			duplicateCount++;
		}
	}

	if (duplicateCount > 1)
	{
		cout << "?";
	}
	else
	{
		cout << (char)(max_index + 65);
	}

	return 0;
}