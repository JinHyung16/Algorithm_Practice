#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ���� �� ���ϱ�4 - ������ �˰���
/// ���� i~j�� �������� ���ؾ��Ѵ�.
/// �� �̸��� �̸� �Է¹����� i��°�� i������ �������� �����ص� ����
/// ���� i�� j�� �Է¹����� vec[j] - vec[i]�� �����ϸ� j������ �����տ��� i���� �������� �� ������ �̴� i~j������ �������̴�
/// �̶� �������� �����ؾ� �ϴµ�, ���� i���� j�� i�� j�� �����ϴ� ������ �ǹ��ϹǷ�
/// �ᱹ vec[j]�� j�� ������ ���������� ���̰� vec[i]�� i�� ������ ���������� ���̹Ƿ� ���� ������ vec[j] - vec[i-1]���ؼ� i�� ���� ���������� ���� �����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0), M(0); //���� ���� N, ���� ���ؾ� �ϴ� Ƚ�� M
	int I(0), J(0); //���� ���ؾ� �ϴ� ���� I, J
	
	std::cin >> N >> M;
	vector<int> numVec(N + 1, 0);
	for (int n = 1; n <= N; n++)
	{
		std::cin >> numVec[n];
		numVec[n] += numVec[n - 1];
	}

	for (int m = 0; m < M; m++)
	{
		std::cin >> I >> J;
		std::cout << numVec[J] - numVec[I - 1] << "\n";
	}
	return 0;
}