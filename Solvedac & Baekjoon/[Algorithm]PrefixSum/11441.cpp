#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver3 �� ���ϱ� - ������ �˰���
/// prefixSum[a] = b�� a��° index������ �������� b�� �ǹ�.
/// ���� i, j�� ������ ��, �ش� ������ ��������
/// prefixSum[j] - prefixSum[i-1]�� ���ָ� �ȴ�.
/// </summary>


int main(void)
{
	FastIO;
	
	int N = 0, M = 0;
	vector<int> prefixSum;
	int a = 0, i = 0, j = 0; //i��° ������ j��° �������� ��
	cin >> N;
	prefixSum.resize(N + 1, 0);
	for ( int i = 1; i <= N; i++ )
	{
		cin >> a;
		prefixSum[i] = prefixSum[i - 1] + a;
	}
	cin >> M;
	while ( M-- )
	{
		cin >> i >> j;
		cout << prefixSum[j] - prefixSum[i - 1] << "\n";
	}

	return 0;
}