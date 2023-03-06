#include<iostream>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 �Ҿ���� ��ȣ - Greedy �˰���
/// ����1) ���� ó���� �������� ���ڴ�.
/// ����2) �����ؼ� �� �� �̻��� ������ ��Ÿ���� �ʴ´�.
/// ����3) 5�ڸ����� ���� ���ӵǴ� ���ڴ� ����.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	string input;
	std::cin >> input;

	int result(0);
	string caculateNum;
	bool isMinus = false; //plus���� minus���� �������ִ� ����

	for (int i = 0; i <= input.size(); i++)
	{
		//+, -�Ǵ� ���� �� ���̸� ����Ѵ�.
		if (input[i] == '+' || input[i] == '-' || i == input.size())
		{
			if (isMinus)
			{
				result -= stoi(caculateNum);
				caculateNum = " ";
			}
			else
			{
				result += stoi(caculateNum);
				caculateNum = " ";
			}
		}
		else
		{
			//�� �ܿ��� ���ӵǴ� ���ڴ� string�� �����ؼ� �־��ش�.
			caculateNum += input[i];
		}

		if (input[i] == '-')
		{
			isMinus = true;
		}
	}

	std::cout << result << "\n";

	return 0;
}