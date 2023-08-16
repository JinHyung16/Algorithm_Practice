#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 ���� �˻� - ���Ʈ���� �˰���
/// ������ �ڿ� ������� �����ؾ� �ϹǷ� getline���� �Է¹޴´�.
/// ��ü �־��� ���ڿ��� ���� ���� �ܾ ���ϸ鼭 ���� �ٸ��� ������ break�ɰ� bool type�� �ٲ۴�.
/// �� �� �ܾ ī�����ϰ�, break�ؼ� ���� �� ���� ��ü ���ڿ��� ���ϵ��� index�� �ٲ۴�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string input;
	string word;
	getline(cin, input);
	getline(cin, word);
	int duplicationCnt = 0;

	for ( int i = 0; i < input.size(); i++ )
	{
		bool isCheck = true;
		for ( int j = 0; j < word.size(); j++ )
		{
			if ( input[i + j] != word[j] )
			{
				isCheck = false;
				break;
			}
		}

		if ( isCheck )
		{
			duplicationCnt++;
			i += word.size() - 1;
		}
	}
	std::cout << duplicationCnt << "\n";
	return 0;
}