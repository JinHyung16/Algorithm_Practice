#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 ī�� �����ϱ� - Greedy �˰���
/// ������������ ���ĵ� ī�尡 ������, ���ö����� ���� ũ�Ⳣ�� ��� ��� ���س�����.
/// ������ ���� ���� �ٽ� �ְ� �������� �����ؾ��ϴµ�, �Ź� ������ �����ϱ⿡ �켱���� ť�� �̿��غ���
/// priority_queue�� ���� ����� �� queue�� �Ź� ������ �ϴ°ź���, �˾Ƽ� ���ִ°� ����.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //���� ī�� ������ ����
	std::cin >> N;

	int numOne(0), numTwo(0);
	int minCompareCnt(0);

	//<�ڷ���, ����ü, �� ������> �̷��� ������ �ȴ�.
	priority_queue<int, vector<int>, std::greater<int>> cardCompareQueue;
	for (int i = 0; i < N; i++)
	{
		int input;
		std::cin >> input;
		cardCompareQueue.push(input);
	}

	while (cardCompareQueue.size() > 1)
	{
		//priority_queue���� ���� ��(���� ���� ��) �ΰ��� ������ priority_queue���� �����
		numOne = cardCompareQueue.top();
		cardCompareQueue.pop();
		numTwo = cardCompareQueue.top();
		cardCompareQueue.pop();

		//���� �� ���� ���ؼ� �ּ� �� Ƚ���� �ִ´�. �̶� minCompareCnt�� ���� ������ ���� ���� ��꿡 ����ؼ� ���Ѵ�
		minCompareCnt += (numOne + numTwo);

		//priority_queue�� ���� �� ���� ���� �ִ´�.
		cardCompareQueue.push(numOne + numTwo);
	}

	std::cout << minCompareCnt << "\n";

	return 0;
}