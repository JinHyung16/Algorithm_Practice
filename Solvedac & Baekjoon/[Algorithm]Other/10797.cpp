#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 10���� - ���� �˰���
/// vector�� ���� ��ȣ�� �־�ΰ�,
/// day�� ���������� ī�����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int day = 0; //��¥�� ���� �ڸ� ����
	int cnt = 0;
	vector<int> carNums(5, 0);

	std::cin >> day;
	for ( int i = 0; i < 5; i++ )
	{
		std::cin >> carNums[i];
		if ( day == carNums[i] )
		{
			cnt++;
		}
	}

	std::cout << cnt << "\n";
	return 0;
}