#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int divisor_count = 0; //��� ����
	int divisor = 0; //��� �Է¹ޱ�
	vector<int> divisor_vector; //�Է¹��� ���(��) ���� ����Ʈ
	int find_num = 0; //ã�ƾ� �� ��

	cin >> divisor_count;

	for (int i = 0; i < divisor_count; i++)
	{
		cin >> divisor;
		divisor_vector.push_back(divisor);
	}

	//���� �������� ���� ū �� ã�´�
	//������������ sort�ϱ�
	sort(divisor_vector.begin(), divisor_vector.end());
	
	//divisor = (���� ���� ��) * (���� ū ��) -> sort�� (�Ǿ� ��) * (�ǳ� ��)
	find_num = divisor_vector[0]*divisor_vector[divisor_count-1];
	std::cout << find_num;
	 
	return 0;
}