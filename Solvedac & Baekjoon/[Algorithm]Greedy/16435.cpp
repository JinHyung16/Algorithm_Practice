#include<iostream>
#include<vector>
#include<algorithm>

/// <summary>
/// Silver5 ������ũ���� - Greedy �˰���
/// Greedy�� �ذ��� ��, ���� �� ������ �����غ��� �͵� ����.
/// ���� �� �ִ� ������ �ᱹ �����ͺ��� ���ʴ�� �Դ°� �ǹ��ϱ⿡ ������ �غ���
/// </summary>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //������ ���� N
	int L(0); //������ũ���� �ʱ� ����
	std::cin >> N >> L;

	vector<int> fruitHeight(N, 0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> fruitHeight[i];
	}

	std::sort(fruitHeight.begin(), fruitHeight.end());
	for (int i = 0; i < N; i++)
	{
		if (fruitHeight[i] <= L)
		{
			//������ũ������ �� ���̺��� �۰ų� ���� ������ �����̸� ���� �� �ִ�.
			L += 1;
		}
	}

	std::cout << L << std::endl;
	return 0;
}