#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 �Ӹ���Ҽ� - ���ڿ� �˰���
/// �Է¹��� ������ ����, �̰� ������ �� 2���� �غ��ϰ�
/// �� �ΰ��� ������ ���ϸ� �ȴ�.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	int num(0);
	while (true)
	{
		std::cin >> num;
		if (num == 0)
		{
			break;
		}

		string origin = std::to_string(num);
		string copy = origin;
		std::reverse(copy.begin(), copy.end());

		if (origin == copy)
		{
			std::cout << "yes" << "\n";
		}
		else
		{
			std::cout << "no" << "\n";
		}
	}
	return 0;
}