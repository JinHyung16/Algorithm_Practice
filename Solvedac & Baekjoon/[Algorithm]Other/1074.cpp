#include<iostream>
#include<vector>
#include<string>
#include<math.h>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 Z - ���� ���� �˰���
/// �迭�� ũ�Ⱑ 2^N * 2^N�̴�. ���� �̸� �ѹ��� �� ���ٸ� �ᱹ O(N)�ɸ���.
/// ���� �迭�� 4���� �������� ���� �� ��� ������ ���ϴ��� �Ǻ��ϰ�,
/// �ش� ������ Ž���ϵ��� �ٲ۴�.
/// 
/// �� ��и麰�� ù ���� ���� 1��и��� 0, 2��и��� (mid*mid), 3��и���(mid*mid*2) 4��и��� (mid*mid*3)�̴�.
/// ������ �־��� ǥ�� ���� 4������ ������ ù ������ ���� ���� �� �� �ִ�.
/// 
/// �� ��и��� �Ǵ����� ����, �ش� ��и��� ���� Ž���� ���� ���� ���̸� ȥ������ ����.
/// </summary>

using namespace std;

int Search(int x, int y, int n)
{
	if (n < 1)
	{
		return 0;
	}
	int mid = (int)pow(2, n - 1);

	//���� �� -> ������ �� -> ���� �Ʒ� -> ������ �Ʒ� ������� 1 2 3 4�и��̶� �Ѵ�.
	if (x < mid && y < mid)
	{
		//1��и� Ž��
		return Search(x, y, n - 1);
	}
	else if (mid <= x && y < mid)
	{
		//2��и� Ž��
		return (mid * mid) + Search(x - mid, y, n - 1);
	}
	else if (x < mid && mid <= y)
	{
		//3��и� Ž��
		return (mid * mid * 2) + Search(x, y - mid, n - 1);
	}
	else
	{
		//4��и� Ž��
		return (mid * mid * 3) + Search(x - mid, y - mid, n - 1);
	}

}

int main(void)
{
	FastIO;

	int N(0), r(0), c(0); //ũ�� N, r�� c��
	std::cin >> N >> r >> c;

	int result = Search(c, r, N); //���� y ���� x�� �ǹ�

	std::cout << result << "\n";
	return 0;
}