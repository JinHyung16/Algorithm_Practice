#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 ĿƮ���� - ���� �˰���
/// vector�� �������� ������ �Է¹޾� �ִ´�.
/// ���������� �ϱ� ���ؼ� sort�� �������� �񱳸� ���� ���� DescendingOrder �Լ��� �־� �������� �Ѵ�.
/// �� �� k-1 ��° index�� ����Ѵ�. �ֳĸ� vector�� index�� 0���� �����̹Ƿ� 1 �۾ƾ��ϴϱ�
/// </summary>

using namespace std;

bool DescendingOrder(int a, int b)
{
	return b < a;
}

int main(void)
{
	FastIO;
	
	int N(0), k(0); //�������� �� N, ���� �޴� ����� �� k
	int x(0); //�� �л��� ���� x
	
	vector<int> awardScores;
	std::cin >> N >> k;
	for (int i = 0; i < N; i++)
	{
		std::cin >> x;
		awardScores.push_back(x);
	}
	std::sort(awardScores.begin(), awardScores.end(), DescendingOrder);
	std::cout << awardScores[k - 1] << "\n";
	return 0;
}
