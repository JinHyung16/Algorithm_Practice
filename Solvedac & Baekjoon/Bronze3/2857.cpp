#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main(void)
{
	int input_count = 5;

	string fbi_list;
	vector<int> fbi_count; // = {0, }���� �ʱ�ȭ �� 0��° index �ڿ������� ���� push_back�Ǿ� ����

	bool is_exist = false;

	for (int i = 0; i < input_count; i++)
	{
		fbi_list.clear();
		cin >> fbi_list;

		is_exist = false;
		for (int j = 0; j < fbi_list.size(); j++)
		{
			if (j + 2 < fbi_list.length() && fbi_list[j] == 'F' && fbi_list[j + 1] == 'B' && fbi_list[j + 2] == 'I')
			{
				//��� FB �� ���� �̻��� ���� �˻��� ����
				is_exist = true;
				break;
			}
		}

		if (is_exist)
		{
			fbi_count.push_back(i+1);
		}
	}

	if (fbi_count.empty())
	{
		cout << "HE GOT AWAY!\n";
		return 0;
	}

	for (int i = 0; i < fbi_count.size(); i++)
	{
		cout << fbi_count[i] << " ";
	}
	return 0;
}