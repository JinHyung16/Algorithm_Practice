#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 ��ǥ - ���ڿ� �˰���
/// �Է¹ް� A�� a�� ���� B�� b�� ���� �߰���Ų��.
/// �� �� if���� ���� ���ǿ� �°� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int V = 0; //�ɻ������� �� V
	int a = 0, b = 0; //a������ �� b������ ��
	string input;
	std::cin >> V;
	std::cin >> input;

	for ( int i = 0; i < input.size(); i++ )
	{
		if ( input[i] == 'A' )
		{
			a++;
		}
		else
		{
			b++;
		}
	}

	if ( a < b )
	{
		std::cout << "B" << "\n";
	}
	else if ( b < a )
	{
		std::cout << "A" << "\n";
	}
	else
	{
		std::cout << "Tie" << "\n";
	}

	return 0;
}