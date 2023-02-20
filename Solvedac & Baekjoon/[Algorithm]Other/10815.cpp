#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 ���� ī�� - �ڷ� ���� �˰���
/// ���� for���� ������ O(n^2)���� ���� �ð��ȿ� �ذ��ϱ� ��ƴ�.
/// binary_serach�� �̿��ϴµ� �̹� �����ϴ� binary_search�� �̿��ص� �ǰ�,
/// �ƴϸ� �����ص��ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //������ �ִ� ���� ī���� ���� N
	int M(0); //������ �ִ� ���� ī������ �ƴ��� �����ؾ� �ϴ� ���� M
	std::cin >> N;
	vector<int> cards(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> cards[i];
	}

	std::cin >> M;
	vector<int> checkList(M);
	vector<int> checkResult(M, 0);
	for (int i = 0; i < M; i++)
	{
		std::cin >> checkList[i];
	}

	//�������� ����
	std::sort(cards.begin(), cards.end());

	//binary search ���� �κ�
	for (int i = 0; i < M; i++)
	{
		//std::binary_search(cards.begin(), cards.end(), M);
		int right = N - 1;
		int left = 0;
		while (left <= right)
		{
			int mid = (right + left) / 2;
			if (cards[mid] == checkList[i])
			{
				checkResult[i] = 1;
				break;
			}

			if (checkList[i] < cards[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		std::cout << checkResult[i] << " ";
	}
	std::cout << "\n";

	return 0;
}