#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 �������� - DP �˰���
/// 1���� �迭 dp�� N���� �ٿ� ���� ������ ���� �ִ°� �ƴ϶�
/// ���� ������ ��, dp�迭�� 0��°, 1��°, 2��°���� �� ��°���� �� �� �ִ� ������ ���� ū Ȥ�� ���� ���������� ���� �ִ񰪰� �ּڰ��� ���Ѵ�.
/// 
/// �̶� maxdp�� mindp�� ���Ҷ� [1]��° �� �߾ӿ� ������ ���� ���� �������� update�ؾ��Ѵ�. 
/// �ֳĸ� ���� ���ʰ� ���� �������� ���� �ٷ� �� ���� ������ �߾ӿ��� ���� ������ �� �ֱ� �����̴�.
/// 
/// 1�� -> [1-0] [1-1] [2-1]
/// 2�� -> [2-0] [2-1] [2-2]   => ex) 2-0�� ���� [1-0] �Ǵ� [1-1]�� ���� + [2-0] �̷��� �¿� ����ϰ� �߾� update�ϱ�
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //N���� ��
	std::cin >> N;
	
	vector<int> input(3, 0);
	vector<int> mindp(3, 0);
	vector<int> maxdp(3, 0);

	int one(0), three(0);
	std::cin >> maxdp[0] >> maxdp[1] >> maxdp[2]; //ó�� dp�迭�� ���� �ִ´�.
	mindp[0] = maxdp[0];
	mindp[1] = maxdp[1];
	mindp[2] = maxdp[2];

	for(int i = 1; i < N; i++)
	{
		std::cin >> input[0] >> input[1] >> input[2];
		one = maxdp[0];
		three = maxdp[2];

		//�� ������ �������� ���� ���鿡���� �ִ��� ����Ѵ�.
		maxdp[0] = std::max(maxdp[0], maxdp[1]) + input[0]; //0��°�� 0�� 1��°���� ���� ������ �� �ִ�.
		maxdp[2] = std::max(maxdp[1], maxdp[2]) + input[2]; //2��°�� 2��°�� 1��°���� ���� ������ �� �ִ�.
		maxdp[1] = std::max(std::max(one, maxdp[1]), three) + input[1]; //1��°�� ��� ������ ���� ������ �� �ִ�.

		one = mindp[0];
		three = mindp[2];
		mindp[0] = std::min(mindp[0], mindp[1]) + input[0];
		mindp[2] = std::min(mindp[1], mindp[2]) + input[2];
		mindp[1] = std::min(std::min(one, mindp[1]), three) + input[1];
	}

	int maxResult = std::max(std::max(maxdp[0], maxdp[1]), maxdp[2]);
	int minResult = std::min(std::min(mindp[0], mindp[1]), mindp[2]);

	std::cout << maxResult << " " << minResult << "\n";
	return 0;
}