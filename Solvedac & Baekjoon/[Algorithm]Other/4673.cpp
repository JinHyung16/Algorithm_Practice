#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 ���� �ѹ� - ���� �˰���
/// n�� ���Ͽ� n + (n�� �� �ڸ���)�� �ϸ鼭 ���� ����� n�� 0�� �ɶ����� �ݺ��Ͽ� ���� ������ n�� ���� �����ڵ�� �������� �ƴϴ�.
/// �̸� üũ�Ͽ� vector�� self num�� �ƴѰ� false�� �ΰ� �������� ���������� true�͵鸸 ����Ѵ�.
/// </summary>

using namespace std;


int NotSelfNumCheck(int num)
{
	int n = num;
	while (num != 0)
	{
		n += (num % 10);
		num /= 10;
	}
	return n;
}

int main(void)
{
	FastIO;
	
	vector<bool> selfNumVec(10001, true);
	
	for (int i = 1; i <= 10000; i++)
	{
		int notSelfNum = NotSelfNumCheck(i);
		if (notSelfNum <= 10000)
		{
			selfNumVec[notSelfNum] = false;
		}
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (selfNumVec[i])
		{
			std::cout << i << "\n";
		}
	}
	return 0;
}
