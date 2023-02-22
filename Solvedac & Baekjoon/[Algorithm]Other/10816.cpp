#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ���� ī�� 2 - �ڷ� ���� �˰���
/// ������������ ������ ��, binary search�� �����ϸ鼭 ���� count�� ������Ű�� ������,
/// �� ��� �迭�� ũ�Ⱑ ���ٸ�, O(NM)���� �ð��ʰ��� ���.
/// ���� Upper Bound�� Lower Bound�� �̿��� �ذ��Ѵ�.
/// lower_bound�� ã������ key ������ ���ų� ū ���ڰ� �迭 �� ��°�� �ִ���
/// upper_bound�� ã������ key���� �ʰ��ϴ� ���ڰ� �迭 �� ��°�� �ִ��� ã�� �����̴�.
/// ��� ���� ���� �������� �Ǿ� �־�� �Ѵ�.
/// 
/// ����)�� UpperBound, LowerBound �Լ��� const vector<int>& vec���� �����ؼ�
/// �Է¹��� ���� �����ϴ� cards�� checkList vector�� �۷ι��� �������� �ʰ� ����Ϸ��� ������,
/// ������ �ð��ʰ��� �����.
/// </summary>

using namespace std;

int N(0), M(0); //����̰� ���� �ִ� ī�� N��, ���� �ִ��� Ȯ���� ī�� ���� M
vector<int> cards;
vector<int> checkList;
int UpperBound(int key)
{
	int left = 0, right = N;
	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (key < cards[mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	return right;
}

int LowerBound(int key)
{
	int left = 0; int right = N;
	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (key <= cards[mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	return right;
}

int main(void)
{
	FastIO;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		std::cin >> input;
		cards.push_back(input);
	}

	//�������� ����
	std::sort(cards.begin(), cards.end());

	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		int input;
		std::cin >> input;
		checkList.push_back(input);
	}

	for (int i = 0; i < checkList.size(); i++)
	{
		std::cout << (UpperBound(checkList[i]) - LowerBound(checkList[i])) << " ";
	}
	std::cout << "\n";
	return 0;
}