#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ����ũ����Ʈ - ���Ʈ���� �˰���
/// ���� �����Ͽ� �κ��� �ִ� �ð��� 2��
/// ���� ���� ��ǥ ���� ���� �ø��µ� 1��
/// 
/// ���� �ּ� ���̺��� �ִ� ���̱��� ��� ������ ���鼭
/// �κ����� ������ Ƚ���� ���� �����ϴ� Ƚ���� ������´�.
/// �κ����� ����Ƚ�� <= (B+������ �����ϴ� Ƚ��)��� �ǹ̴�
/// �κ����� ���� ������ (���� �����ִ� ���� + �����Ͽ� �κ��� ���� ��)�� �ǹ��Ѵ�.
/// �̶� minTime�� ���ϰ� �̶��� h���� ���Ѵ�.
/// </summary>

using namespace std;

vector<vector<int>> ground(500, vector<int>(500,0));

int main(void)
{
	FastIO;
	
	int N(0), M(0), B(0); //���� N, ���� M, ���۽� �κ��� ����ִ� ��� ���� B
	std::cin >> N >> M >> B;

	int maxHeight(256); //���� �ִ� ����
	int minTime(987654321); //���� �����ϰ� �״µ� �ɸ� ���� �ּ� �ð�
	int mostHeightGround(0); //���� ���� ���� ����

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> ground[i][j];
		}
	}

	for (int h = 0; h <= maxHeight; h++)
	{
		int subToInven = 0; //�κ����� ���� Ƚ��
		int removeHeight = 0; //���� ������ Ƚ��
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int height = ground[i][j] - h;
				if (0 < height)
				{
					//���� ���ٸ� ���� �����Ѵ�
					removeHeight += height;
				}
				else if(height < 0)
				{
					//���� ���ٸ�
					subToInven -= height;
				}
			}
		}

		if (subToInven <= (B + removeHeight))
		{
			int time = (removeHeight * 2) + subToInven;
			if (time <= minTime)
			{
				minTime = time;
				mostHeightGround = h;
			}
		}
	}

	std::cout << minTime << " " << mostHeightGround << "\n";

	return 0;
}