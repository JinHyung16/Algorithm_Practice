#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 ���ڿ� - ���� �˰���
/// ������ �ذ��� �� ���ڿ� ���̿� ���� ����� �ٸ����Ѵ�.
/// �ֳĸ� ���̰� 1���� ũ�� 0��°�� length()-1 ��° index�� ���������
/// ���̰� 1�̸� 0��°�� ù ��°���� �������� �ǹǷ� �̸� 2�� ����ؾ� �ϱ� �����̴�.
/// </summary>


int main(void)
{
	FastIO;
	
	int T = 0; //�׽�Ʈ ���̽� ���� T
	cin >> T;
	string input;
	while ( T-- )
	{
		cin >> input;
		if ( 1 < input.size() )
		{
			cout << input[0] << input[input.length() - 1] << "\n";
		}
		else
		{
			cout << input[0] << input[0] << "\n";
		}
		cin.clear();
	}
	return 0;
}