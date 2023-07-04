#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 �ڵ��� ��ȣ ���� - DP �˰���
/// string���� �Է��� ���� ��, �� ��ȣ�� int�� �ٲ� ���ʴ�� phoneNums ���Ϳ� �ִ´�.
/// �� �� while(true)�� ���鼭 temp ���͸� ����� (phoneNums[i] + phoneNums[i+1]) % 10�� �Ͽ� temp�� �ְ�
/// �� ����ϸ� phoneNums�� ������ temp���� �ְ�, temp�� ���� ������ phoneNums.size()�� 2�� �ɶ����� �ݺ��Ѵ�.
/// 
/// %10�� �ϴ� ������, string�� i��°�� int�� �ٲ㼭 ���� �� �ش� �ڸ����� ���� ���� �����̴�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string strA, strB; //A�� B�� ��ȭ��ȣ
	vector<int> phoneNums;

	std::cin >> strA;
	std::cin >> strB;

	int phoneNumSize = strA.size() + strB.size();

	for(int i = 0; i < strA.size(); i++)
	{
		int intA = strA[i] - '0';
		int intB = strB[i] - '0';

		phoneNums.push_back(intA);
		phoneNums.push_back(intB);
	}

	vector<int> temp;
	while( true )
	{
		for(int i = 0; i < phoneNums.size() - 1; i++)
		{
			temp.push_back((phoneNums[i] + phoneNums[i+1]) % 10);
		}
		phoneNums.clear();
		phoneNums = temp;
		temp.clear();

		if(phoneNums.size() == 2)
		{
			std::cout << phoneNums[0] << phoneNums[1] << "\n";
			break;
		}
	}
	return 0;
}