#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 �� �� - ���� �˰���
/// c++ STL���� �����ϴ� sort�� O(nlogn)�̹Ƿ� ����Ͽ�
/// 1��° index�� ����ϸ� �ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	vector<int> sortVec(3, 0);
	std::cin >> sortVec[0] >> sortVec[1] >> sortVec[2];

	std::sort(sortVec.begin(), sortVec.end());

	std::cout << sortVec[1] << "\n";
	return 0;
}

