#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	// alphabat 'a' to 'z' -> total count 26개
	// 빈도수를 저장하는 배열 생성
	// ASCII 소문자 97~122, 대문자 65~90
	int alphabat[26] = { 0, };
	
	string s_input = "";
	int duplicateCount = 0;

	cin >> s_input;

	for (int i = 0; i < s_input.length(); i++)
	{
		if (s_input[i] < 97)
		{
			// 대문자라면
			alphabat[s_input[i] - 65] ++;
		}
		else
		{
			// 소문자라면
			alphabat[s_input[i] - 97] ++;
		}
	}

	int max = 0, max_index = 0;

	// alpahbat 수만큼 배열 다 돌기
	// 어떤 알파벳이 들어와서 값이 변했는지 모르기에 다 돌아서 체크해야함
	for (int i = 0; i < 26; i++)
	{
		if (max < alphabat[i])
		{
			max = alphabat[i];
			max_index = i;
		}
	}

	// 가장 많이 사용된 알파벳이 여러개인지 검사
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