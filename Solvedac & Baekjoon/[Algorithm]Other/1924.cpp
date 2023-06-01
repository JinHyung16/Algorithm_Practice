#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 2007�� - ���� �˰���
/// �Էµ� x�� y���� �޴´�.
/// �׸��� x������ 1���� �����ϸ鼭 �ش� x���� ���� y���� �ݴ�� ������ ���Ѵ�.
/// �̷��� x�� 1���� Ŭ������ �ݺ��Ͽ� ���� �� ������ y���� ã��
/// y & 7�� ���� day�� ������ vector�� index�� ����� ����Ѵ�.
/// �̶�, ���� ���� ���ҽ��Ѿ� �ϴµ�, 9�� 2���� ��� ������ 9���� �� ���� �ʾұ⿡ ���� x�� ���ҽ�Ű�� y�� ���ҽ�Ų x�� �ش��ϴ� ���� ���ؾ��Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int x(0), y(0); //x�� y��
	std::cin >> x >> y;

	vector<string> dayVec = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	while (1 < x)
	{
		x--; //���� ���� ���ҽ��Ѿ��Ѵ�.
		if (x == 2)
		{
			y += 28;
		}
		else if (x == 4 || x == 6 || x == 9 || x == 11)
		{
			y += 30;
		}
		else
		{
			y += 31;
		}
	}
	
	y %= 7;
	
	std::cout << dayVec[y] << "\n";
	return 0;
}
