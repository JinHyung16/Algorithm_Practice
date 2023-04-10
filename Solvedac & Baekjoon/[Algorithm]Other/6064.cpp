#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ī�� �޷� - ���� �˰���
/// <x:y>���� �� x,y�� �ִ밪�� M,N�ΰ��̴�.
/// �������� �� x,y�� �־��� �ִ밪�� ������ 1�� �ʱ�ȭ�� �ƴϸ� +1�� ������Ų�ٰ� �ߴ�. 
/// ���� ���� ���ø� ���� M=10, N=12��, 10��° �ش� <10,10>, 11��° �ش� <1, 11> 12��° �ش� <2,12> 13��° �ش� <3,1>�̴�.
/// ������ 1�� �������Ѱ��鼭 Ǯ�ٺ��� O(MN)���� �ð��ʰ��� ����.
/// 
/// Ǯ��)
/// ������� M=5, N=6, x=3, y=4�̸�
/// 1. �켱 ����⵵�� �����Ѵ�. x�� M�� �Ѱų�, y�� N�� �ȴٸ� ����⵵��.
/// 2. maxYear�� ���� ���� x�� �� ���� �Ѱų� (x-1) % N + 1 == y�� ����⵵�� �����.
/// 3. maxYear < x�� -1�� �ƴϸ� x += M�Ѱ��� ����Ѵ�.
/// 
/// maxYear�� ��� M, N�� �ּ� ������� ����⵵�̴�.
/// </summary>

using namespace std;

int GCD(int a, int b)
{
	int temp(0);
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

int main(void)
{
	FastIO;

	int T(0); //test case
	int M(0), N(0), x(0), y(0); //�־��� M, N, x, y
	std::cin >> T;
	while (T--)
	{
		std::cin >> M >> N >> x >> y;
		int maxYear = LCM(M, N);
		while (true)
		{
			if (maxYear < x || (x - 1) % N + 1 == y)
			{
				break;
			}
			x += M;
		}

		if (maxYear < x)
		{
			std::cout << -1 << "\n";
		}
		else
		{
			std::cout << x << "\n";
		}
	}
	return 0;
}