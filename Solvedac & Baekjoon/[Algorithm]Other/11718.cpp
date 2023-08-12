#include<iostream>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze5 �״�� ����ϱ� - ���ڿ� �˰���
/// std::cin�� ���� �Է¹��� ������ �״�� std::cout�Ѵ�
/// �̶� �������� ���� �Է½� ������ ������� �ʰ� �����̹Ƿ�,
/// getline�� ���� �Է¹޾� �����̸� break�� ������.
/// �̶� input == " "�� input == ""�� ���̰� �����Ƿ� �˾Ƶ���.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	string input;
	while ( true )
	{
		getline(std::cin, input);
		if ( input == "" )
		{
			break;
		}
		std::cout << input << "\n";
	}
	return 0;
}