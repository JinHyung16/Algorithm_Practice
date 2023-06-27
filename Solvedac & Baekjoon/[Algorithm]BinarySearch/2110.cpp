#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 ������ ��ġ - �̺� Ž�� �˰���
/// 
/// ���� ������ �� �������� ������ �Ÿ��� �ִ�� �ؾ��Ѵ�.
/// routers ���Ϳ� ������ ��ġ�� �� �Է¹޾����� �����Ͽ� ���� ���� ���� ū ���� �켱 �����صΰ� �����Ѵ�.
/// �̺� Ž���� ���ؼ� left = 0, right = routers[routers.size() - 1], mid = (left + right) / 2�� ���� �����Ѵ�.
/// 1) while(left <= right)�� ���� ������ �� ������ ������ �ִ� �Ÿ����� ã�´�.
/// 2) for���� ���� ��������� �Ÿ� ���̸� ���鼭 mid������ ū�� ������ ���� ũ�� �����⸦ ��ġ�ϰ� index�� ��ġ�� ������ index ������ �ٲ۴�.
/// 3) ��ü ��ġ�ؾ��ϴ� ������ ������ ���� ��ġ�� ������ ���ϸ鼭 left �Ǵ� right�� ������ ���� ���Ѵ�.
/// </summary>

using namespace std;

vector<int> routers;

int main(void)
{
	FastIO;
	
	int N = 0, C = 0; //���� ���� N�� �������� ���� C
	std::cin >> N >> C;
	for(int i = 0; i < N ; i++)
	{
		int x = 0;
		std::cin >> x;
		routers.push_back(x);
	}

	std::sort(routers.begin(), routers.end());

	int left = 0;
	int right = routers[routers.size() - 1];
	int maxDist = -1;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		int installCnt = 1, start = 0; //���� ��ġ�� ������ ������ index ��ȣ

		for(int j = 0; j < N; j++)
		{
			if(mid <= routers[j] - routers[start])
			{
				installCnt += 1;
				start = j; //�����⸦ ��ġ������ ��� ��ġ�� index ��ȣ�� ��ü�Ѵ�.
			}
		}

		if(C <= installCnt)
		{
			maxDist = std::max(maxDist, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	std::cout << maxDist << "\n";
	return 0;
}