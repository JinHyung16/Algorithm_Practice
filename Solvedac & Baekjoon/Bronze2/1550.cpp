#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;


int main(void)
{
	string hex_number;
	int convert_num = 0;

	vector<int> decimal_list;
	int decimal_sum = 0;

	cin >> hex_number;

	for (int i = 0; i < hex_number.size(); i++)
	{
		switch (hex_number[i])
		{
		case 'A':
			decimal_list.push_back(10);
			break;
		case 'B':
			decimal_list.push_back(11);
			break;
		case 'C':
			decimal_list.push_back(12);
			break;
		case 'D':
			decimal_list.push_back(13);
			break;
		case 'E':
			decimal_list.push_back(14);
			break;
		case 'F':
			decimal_list.push_back(15);
			break;
		default:
			convert_num = hex_number[i] - 48;
			decimal_list.push_back(convert_num);
			break;
		}
	}

	for (int i = 0; i < decimal_list.size(); i++)
	{
		decimal_sum += decimal_list[i] * pow(16, decimal_list.size() - 1 - i);
	}

	cout << decimal_sum;

	return 0;
}