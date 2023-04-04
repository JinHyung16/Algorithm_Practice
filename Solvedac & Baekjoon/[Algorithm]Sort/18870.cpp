#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ��ǥ ���� - ���� �˰���
/// ������ �ǹ̴� ������ ����.
/// ���� �����߿� i��°���� ������ ���� ������ �ִ��� ���� �� ������ X'i�� ǥ���ϴ� ���̿���.
/// �� ��ǥ�� �����Ѵٴ°� i��° ���� ���� ������ i���� ���� ������ ������ ��ü�Ѵٴ� ���� �ǹ�
/// 
/// vector<pair<int,int>>�� �̿��� �ش� ����, ������ �����ص״�.
/// �׸��� ���� vector<pair<int,int>> �迭�� �ϳ� �� �����, ���� �迭�� �������� �����صд�.
/// ���� �迭�� ���鼭, �ߺ��Ǵ� ���̸� ���ο� �迭���ٰ� (���� ���� ����, ������ ���� ������ ����)�� ����
/// 
/// ���� ���� ���� ����� ���������ڸ� ����ؾ� n=n+1���� �տ� n�� ����ǰ�, ���������ڸ� ����ϸ� ���� n+1�� �ִ� n�� ������� �ٽ��ѹ� �����.
/// ���� ���� ������ ���� ���� 1�� ���� ���ü� ������ ��������.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	int N(0); //N���� ��ǥ
	std::cin >> N;

	vector<pair<int, int>> position;
	vector<pair<int, int>> result;
	int minCnt(0); //������ ���� ������

	for(int i = 0; i < N; i++)
	{
		int input(0);
		std::cin >> input;
		position.push_back({ input, i });
	}
	std::sort(position.begin(), position.end());

	result.push_back({ position[0].second, 0 });
	for (int i = 1; i < N; i++)
	{
		//�ߺ��Ǵ� ���̸�
		if (position[i - 1].first == position[i].first)
		{
			result.push_back({ position[i].second,minCnt }); //������ �������� ������ ���� 0��
		}
		else
		{
			//������ ���� ������ �� ���� �տ��ִ� ����ŭ �߰�
			result.push_back({ position[i].second, minCnt += 1 }); //���� ������(++minCnt) �Ǵ� ������ ���� ���
		}
	}

	std::sort(result.begin(), result.end());
	for (int i = 0; i < N; i++)
	{
		std::cout << result[i].second << " ";
	}
	return 0;
}