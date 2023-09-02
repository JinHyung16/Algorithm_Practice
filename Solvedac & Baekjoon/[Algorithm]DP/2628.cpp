#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 �����ڸ��� - DP �˰���
/// ����, ���θ� �Է¹޾� ���� �� ���� ū ���� ���� ���Ѵ�.
/// �̶� Set�� �־�, �ߺ� ���� �����. ��� ���� ���̸� ���̰� 0���� ������ �ȵ��״� �������.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int width = 0, height = 0; //���ο� ������ ����
	int dotCnt = 0; //Į�� �߶���ϴ� ������ ����
	set<int> wid;
	set<int> hei;

	std::cin >> width >> height;
	std::cin >> dotCnt;
	for ( int i = 0; i < dotCnt; i++ )
	{
		int c1 = 0, c2 = 0;
		std::cin >> c1 >> c2;
		if ( c1 == 0 )
		{
			wid.insert(c2);
		}
		else
		{
			hei.insert(c2);
		}
	}

	wid.insert(0);
	wid.insert(height);
	hei.insert(0);
	hei.insert(width);

	vector<int> widVec(wid.begin(), wid.end());
	vector<int> heiVec(hei.begin(), hei.end());

	std::sort(widVec.begin(), widVec.end());
	std::sort(heiVec.begin(), heiVec.end());

	int maxWidth = 0, maxHeight = 0;
	for ( int i = 0; i < widVec.size() - 1; i++ )
	{
		maxWidth = std::max(maxWidth, widVec[i + 1] - widVec[i]);
	}
	for ( int i = 0; i < heiVec.size() - 1; i++ )
	{
		maxHeight = std::max(maxHeight, heiVec[i + 1] - heiVec[i]);
	}

	std::cout << maxWidth * maxHeight << "\n";
	return 0;
}