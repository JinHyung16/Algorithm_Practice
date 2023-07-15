#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 FA - �ֵ� Ȥ �˰���
/// 1�ڸ� ���� ���ؼ� FA�� �����ϸ� ��� 1�ڸ� ���� ������ FA��
/// �׷��ٸ� 2�ڸ� �� �̻� ���ؼ� �Ǻ��ϸ� �ȴ�.
/// 2�ڸ� �� �̻� ���� ���ؼ� FA�� �����ϸ� ��� �ڸ����� �۾�����.
/// ���� �Է��� ���̸�ŭ FA�� ������ �ڸ����� 1�ڸ��� FA �ƴϸ� NFA�� ����ϸ� �ȴ�.
/// </summary>

using namespace std;

string FA(string x)
{
	string temp;
	temp = ((x[0] - '0') * x.size()) + '0';
	return temp;
}

int main(void)
{
	FastIO;

	string x;
	std::cin >> x;

	for ( int i = 0; i < x.size(); i++ )
	{
		x = FA(x);
	}

	if ( x.size() == 1 )
	{
		std::cout << "FA" << "\n";
	}
	else
	{
		std::cout << "NFA" << "\n";
	}
	return 0;
}