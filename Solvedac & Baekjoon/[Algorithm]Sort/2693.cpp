#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 N��° ū �� - ���� �˰���
/// std::sort�� �̿��ϸ� log N���� sort�� �ȴ�.
/// �̶� sort(vector.rbegin(), vector.rend()); �� ū ������ �������� ������ �ǹ��Ѵ�.
/// �� �� �迭�� 0��°���� �����̴� 3��° ū ���� ����Ϸ��� index������ 2�� �־���Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int T = 0; //�׽�Ʈ ���̽� ����
	std::cin >> T;
	vector<int> sortVec(10, 0);
	while ( T-- )
	{
		for ( int i = 0; i < 10; i++ )
		{
			std::cin >> sortVec[i];
		}
		std::sort(sortVec.rbegin(), sortVec.rend());
		std::cout << sortVec[2] << "\n";
	}
	return 0;
}