#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 ��ȭ���� �� - ���Ʈ���� �˰���
/// ó���� �ܼ��� 666�� �ٿ��� ����ߴ�. �׷��� ���� ����� ���� �׷��� �ϸ� �ȵȴ�.
/// ���� 666�� �� ���ڴ� 1000���� ���� �������� 666�̸� ����ϸ�ȴ�.
/// �̶� movieTitle�� ��ȭ ������, endCnt�� ���� �� ��° ������ �������� �����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0);
	std::cin >> N;

	int endNum = 666;
	int movieTitle(0), endCnt(0);
	int temp(0);
	while(endCnt != N)
	{
		movieTitle++;
		temp = movieTitle;
		while (temp != 0)
		{
			if (temp % 1000 == endNum)
			{
				endCnt++;
				break;
			}
			else
			{
				temp /= 10;
			}
		}
	}

	std::cout << movieTitle << "\n";
	return 0;
}