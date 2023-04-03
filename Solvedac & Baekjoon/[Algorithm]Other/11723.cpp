#include<iostream>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 ���� - ���Ʈ���� �˰���
/// �ΰ��� ������� �ذ��� �� �ִ�.
/// 1) �迭�� ����� ���� ���ǿ� ���� �ذ�
/// 2) ��Ʈ����ũ ������ �ذ�
/// ��Ʈ ����ũ ���õ� ���δ� https://rebro.kr/63 �����ߴ�.
/// ��Ʈ ����ũ�� int�� 4byte�� 8bit�� �ǹ� �̶� �� bit�� �̿��ϴ°��̴�.
/// ��ǻ�� ������ ��� ���� Not, Xor, And, Or, Shift ���� ������ Ȱ���Ѵ�.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	
	int M(0); //�����ؾ� �ϴ� ������ ��
	string input;
	int bit(0), val(0);
	std::cin >> M;
	while (M--)
	{
		std::cin >> input;
		if (input == "add")
		{
			std::cin >> val;
			bit |= (1 << val);
		}
		else if (input == "remove")
		{
			std::cin >> val;
			bit &= ~(1 << val);
		}
		else if (input == "check")
		{
			std::cin >> val;
			if (bit & (1 << val))
			{
				std::cout << 1 << "\n";
			}
			else
			{
				std::cout << 0 << "\n";
			}
		}
		else if (input == "toggle")
		{
			std::cin >> val;
			bit ^= (1 << val);
		}
		else if (input == "all")
		{
			//21�� ��Ʈ�� �ٲ� ���� ����Ʈ 1ĭ �� 1�� ���Ƿ� 1~20���� ǥ��
			bit = (1 << 21) - 1;
		}
		else if (input == "empty")
		{
			bit = 0;
		}
	}
	return 0;
}