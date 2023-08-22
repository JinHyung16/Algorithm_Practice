#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ���� - ������ �˰���
/// �������� ����, prefix[i]�� ���� ���� ���ؼ� ��� �־�д�.
/// �� �� i = K to N�ؼ� result�� prefix[i] - prefix[i-K]���� �ִ´�.
/// 
/// 08��21�� ������ Ǯ�� ä���� ���ߴ�.
/// 08��22�� ä�� ��� Ʋ�ȴ�... �׷��� �ٽ� �����ؼ� Ǯ�� �÷ȴ�.
/// Ʋ�� ������ result�� MIN���� �ʱ�ȭ ���ؼ� Ʋ�ȴ�. 
/// �� �ʱ�ȭ �ؾ��ϳĸ� �������� ���� �� �ֱ� �����̴�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, K = 0; //�µ��� ������ ��ü ��¥ N, ���� ���ϱ� ���� �������� ��¥ K
	std::cin >> N >> K;
	vector<int> prefix(N + 1, 0);
	int result = -987654321; //�� �����ϼ� ������ �����ؼ� �ʱ�ȭ����

	for ( int i = 1; i <= N; i++ )
	{
		int input = 0;
		std::cin >> input;
		prefix[i] = prefix[i - 1] + input;
	}

	for ( int i = K; i <= N; i++ )
	{
		result = std::max(result, prefix[i] - prefix[i - K]);
	}
	std::cout << result << "\n";
	return 0;
}