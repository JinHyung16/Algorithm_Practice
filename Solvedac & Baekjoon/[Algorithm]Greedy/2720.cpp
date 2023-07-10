#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 ��Ź�� ���� ���� - Greedy �˰���
/// �Ž������� �Է¹޴´�.
/// coins ���Ϳ��� ���� ū ������ �׼����� �־�д�.
/// �� �� C / coins[i]�� ����ϰ� C %= coins[i]�� ���� �� ���� �������� ���� i���� �� �Ž����� ���� �׼��� �Ѱ��ش�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int T = 0, C = 0; //�׽�Ʈ ���̽� ���� T, �Ž����� C
	vector<int> coins = { 25, 10, 5, 1 }; //quarter, dime, nickel, penny ������ �׼��� *100 �ؼ� ȯ����
	
	std::cin >> T;
	
	while ( T-- )
	{
		std::cin >> C;
		for ( int i = 0; i < coins.size(); i++ )
		{
			std::cout << C / coins[i] << " ";
			C %= coins[i];
		}
		std::cout << "\n";
	}
	return 0;
}