#include<iostream>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ������� ���� - Graph �˰���
/// 1. �־����� ����� �������� �׻� ���� �׷����� �̷��.
/// 2. ����ġ�� �������� �ʴ´�.
/// �� �̴� MST�� �ǹ��ϴµ�, MST�� ������ ������ ������ (��� - 1)����.
/// 
/// ���� ������ ���� N�� ����̹Ƿ�,
/// Ÿ���� ����� ������ �ּ� ���� �� ������ N - 1�ϸ� �ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int T(0); //�׽�Ʈ ���̽�
	int N(0), M(0); //������ �� N, ������� ���� M
	int a(0), b(0); //����Ⱑ �պ��ϴ� a�� b
	std::cin >> T;

	while (T--)
	{
		std::cin >> N >> M;
		for (int i = 0; i < M; i++)
		{
			std::cin >> a >> b;
		}
		std::cout << N - 1 << "\n";
	}

	return 0;
}