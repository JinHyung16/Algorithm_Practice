#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 A+B-6 - ���ڿ� �˰���
/// ,�� �׻� string�� index 1��°�̹Ƿ�
/// 0���� 2�� index���� int���� �����´�.
/// �̶� string[0] - '0'�� ����� �ƽ�Ű �ڵ尡 ��ȯ�ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int T = 0; //�׽�Ʈ ���̽� ���� T
	std::cin >> T;
	while ( T-- )
	{
		int a = 0, b = 0;
		string input;
		std::cin >> input;
		a = input[0] - '0';
		b = input[2] - '0';

		std::cout << a + b << "\n";
	}
	return 0;
}