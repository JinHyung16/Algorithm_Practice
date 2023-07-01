#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 Ʈ�� ����� - Ʈ�� �˰���
/// Ʈ���� Ư���� �ľ��غ���, ���� ���� ������ 1�� ��带 �ǹ��Ѵ�.
/// ���� n-m���� �̾����� ��带 ���̴ٰ�, m���� ������ �ʿ��ϴٸ� n-m ��� �ڿ� �ϳ��� ���δ�.
/// ex)n=4, m=2�� ���
/// 0 -> 1- > 2 -> 3 ������ �����ϸ� ��� 2���� 3���� ��� ������ ���� 2���� �����Ѵ�.
/// 
/// ex)n=4, m=3�� ���
/// 0 -> 1 -> 2
///	       -> 3
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int n = 0, m = 0; //n���� ���, m���� ����
	std::cin >> n >> m;

	for(int i = 0; i < n - 1; i++)
	{
		if(i < n - m)
		{
			//n-m���� ��带 �̾� ���δ�.
			std::cout << i << " " << i + 1 << "\n";
		}
		else
		{
			//n-m ���ĺ��� ���� n-m ���� ���ڿ� ��带 ���δ�.
			std::cout << n - m << " " << i + 1 << "\n";
		}
	}
	
	return 0;
}