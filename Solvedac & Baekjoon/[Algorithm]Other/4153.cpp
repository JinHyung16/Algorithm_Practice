#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 �����ﰢ�� - ���� �˰���
/// �ﰢ���̵Ƿ��� (���� ����) + (���� ����) = (���� ����)�̸� �ﰢ���̴�.
/// ������ ���� �Է� ������ �������� �ʾҴ�. �̿� ���̸� ���� ���� �� ���̸� �������� �����Ѵ�.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	string triangle = "right";
	string nonTriangle = "wrong";
	int w(0), l(0), h(0); //���� ���� ���� ������� �Է¹޴´�.
	while (true)
	{
		int temp = 0;
		std::cin >> w >> l >> h;
		if (w == 0 && l == 0 && h == 0)
		{
			break;
		}

		if (w > l)
		{
			temp = l;
			l = w;
			w = temp;
		}
		if (l > h)
		{
			temp = h;
			h = l;
			l = temp;
		}

		int powH = (h * h);
		int powWL = (w * w) + (l * l);

		if (powH == powWL)
		{
			std::cout << triangle << "\n";
		}
		else
		{
			std::cout << nonTriangle << "\n";
		}
		
	}

	return 0;
}