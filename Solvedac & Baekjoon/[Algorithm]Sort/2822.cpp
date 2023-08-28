#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 ���� ��� - ���� �˰���
/// ������ �Է¹ް�, �̶� �ش� �Է� ������ vector<pair<int,int>>�� ���� �Է¹ް�
/// ������ ū ������ �������� �Ѵ�.
/// �� �� 5���� ���� ���ϰ�, �ش� ���� ��ȣ�� �ٽ� vector�� �ű��.
/// �ű� vector�� ���������Ͽ� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int sum = 0;
	vector<pair<int, int>> scores(8);
	vector<int> nums;
	for ( int i = 0; i < 8; i++ )
	{
		std::cin >> scores[i].first;
		scores[i].second = i + 1;
	}
	std::sort(scores.begin(), scores.end(), std::greater<pair<int, int>>());

	for ( int i = 0; i < 5; i++ )
	{
		sum += scores[i].first;
		nums.push_back(scores[i].second);
	}

	std::sort(nums.begin(), nums.end());

	std::cout << sum << "\n";
	for ( int i = 0; i < 5; i++ )
	{
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
	return 0;
}