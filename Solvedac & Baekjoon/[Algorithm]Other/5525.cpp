#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 IOIOI - ���ڿ� �˰���
/// PN�� �ᱹ IOI�� ������ �ǹ��Ѵ�.
/// ���� ���ڿ����� IOI�� ������ �ľ��ϸ�ȴ�.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	
	int N(0), M(0); //���ڿ� ���� N, ���ڿ� ���� M
	string input;
	
	std::cin >> N;
	std::cin >> M;
	std::cin >> input;

	int result(0);
	for (int i = 0; i < M; i++)
	{
		int ioiLength(0);
		if (input[i] == 'I')
		{
			while (input[i + 1] == 'O' && input[i + 2] == 'I')
			{
				i += 2; //i���� 2ĭ �� ���� �����Ѵ�. �׷��� IOI�� Ȯ���Ѱ�
				ioiLength++;			
				if (ioiLength == N)
				{
					ioiLength--; //�׷��� ���� IOIüũ�� ������ų �� ����
					result++;
				}
			}
		}
	}

	std::cout << result << "\n";
	return 0;
}