#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 Ļ�ŷ� ������2 - Greedy �˰���
/// �ٱ��� �� Ļ�ŷ� �� �� ������ �ٸ� �� Ļ�ŷ� ������ ���� ��ǥ�� �����Ѵ�.
/// ���� B-A �� C-B �� �� ū ���� ã�´�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int A = 0, B = 0, C = 0;

	while ( std::cin >> A >> B >> C )
	{
		int result = std::max(B - A, C - B);
		std::cout << result - 1 << "\n";
	}
	return 0;
}