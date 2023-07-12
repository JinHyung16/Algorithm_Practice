#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 ���� ������ - ������ �˰���
/// ������ ���� �����صд�.
/// �� �� sum�� result + ������ i��° ���� �����ϰ�
/// sum�� 100���� ũ�ų� ���� �� result�� sum�� ���� 98�� 102��� 102�� ����ؾ� �ϹǷ� �̸� ���Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	vector<int> mushroom(10, 0);
	for ( int i = 0; i < 10; i++ )
	{
		std::cin >> mushroom[i];
	}

	int result = 0;
	for ( int i = 0; i < 10; i++ )
	{
		int  sum = result + mushroom[i];
		if ( 100 <= sum )
		{
			if ( sum - 100 <= 100 - result )
			{
				std::cout << sum << "\n";
			}
			else
			{
				std::cout << result << "\n";
			}
			return 0;
		}
		result = sum;
	}
	std::cout << result << "\n";
	return 0;
}