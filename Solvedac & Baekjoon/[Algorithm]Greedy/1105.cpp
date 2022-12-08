#include<iostream>
#include<string>

using namespace std;

/// <summary>
/// Silver1 �� - Greedy �˰���
/// L�� R�� �־����µ�, R�� L���� ũ�ų� ����! �� �ڸ����� �������
/// ���� L�� R�� ũ�⸦ �� ���� type�� �� ������
/// </summary>


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int eightMinCount = 0;
	string L, R;
	std::cin >> L >> R;

	if (L.size() != R.size())
	{
		std::cout << 0 << std::endl;
	}
	else
	{
		for (int i = 0; i < L.size(); i++)
		{
			if (L[i] != R[i])
			{
				break;
			}
			if (L[i] == R[i] && L[i] == '8')
			{
				eightMinCount++;
			}
		}
		std::cout << eightMinCount << std::endl;
	}

	return 0;
}