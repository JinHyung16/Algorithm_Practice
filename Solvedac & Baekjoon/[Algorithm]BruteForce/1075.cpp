#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 ������ - ���Ʈ���� �˰���
/// N = N - N % 100�� �� ������, N�� 23442�� 23400���� �����ϸ� �ٷ� ���� �������� �����̸�
/// F�� �ִ� 100�̱⿡ N % 100�� ���� �������� �� ������ �����ϱ� �����̴�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	long long N = 0, F = 0; //N�� F�� ������.
	string result;

	std::cin >> N >> F;
	N = N - N % 100;
	while ( true )
	{
		if ( N % F == 0 )
		{
			break;
		}
		N++;
	}

	result = std::to_string(N);
	std::cout << result[result.size() - 2] << result[result.size() - 1] << "\n";
	return 0;
}