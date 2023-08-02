#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 Ȧ���ϱ� ¦���ϱ� - ���ڿ� �˰���
/// ���ڿ��� �Է¹ް�, length()-1�� �Ѵ�.
/// ������ string �������� ������ �� ������.
/// �� �� % 2�� �����Ͽ� 0�̸� even(¦��), 1�̸� odd(Ȧ��)�� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //������ ���� N
	std::cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		string input;
		std::cin >> input;
		if ( input[input.length() - 1] % 2 == 0 )
		{
			std::cout << "even" << "\n";
		}
		else
		{
			std::cout << "odd" << "\n";
		}
	}
	return 0;
}