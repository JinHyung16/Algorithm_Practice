#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver4 �ùٸ� �迭 - ���� �˰���
/// </summary>

int main(void)
{
	int continuous_count = 5; //�ǹٸ� �迭�̱� ���� �ʿ��� ���ӵ� ��

	int index_count = 0;
	int number = 0;
	vector<int> number_list;

	cin >> index_count;
	for (int i = 0; i < index_count; i++)
	{
		cin >> number;
		number_list.push_back(number);
	}

	//��������
	sort(number_list.begin(), number_list.end());

	
	int temp = 1;
	for (int i = 0; i < number_list.size(); i++)
	{
		int count = 1; //���� ���غ��� counting

		//i��° ���� �ǹٸ� �迭�� �Ǵ� ���� ������ŭ ������
		for (int j = 1; j < number_list.size(); j++)
		{
			//�� �� ���� ���̺��� ������ ������� count ������
			if (0 < (number_list[j] - number_list[i]) && (number_list[j] - number_list[i]) < 5)
			{
				count++;
			}
		}
		temp = std::max(temp, count);
	}

	if (temp > 5)
	{
		cout << 0;
	}
	else
	{
		cout << continuous_count - temp;
	}
	

	return 0;
}