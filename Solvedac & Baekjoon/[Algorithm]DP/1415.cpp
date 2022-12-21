#include<iostream>
#include<vector>

/// <summary>
/// Gold2 ���� - DP �˰���
/// ������ �ִ� 50��, ������ �ִ� 10000
/// bool type���� �Ҽ��� �ƴѰ͵��� �� true�� �ٲ��ְ� �����Ѵ�.
/// ���� ������ ���ͼ� �ش� ������ �ִ� ���� ���� ���� count�迭�� ����
/// </summary>


using namespace std;

int prices[10001];
bool notPrimeNumbers[500001]; //�Ҽ����� �ƴ��� ���� �迭
long long countArr[500001];

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int candyCount(0);
	countArr[0] = 1;
	
	//memset(primeNumbers, true, sizeof(primeNumbers));
	notPrimeNumbers[0] = notPrimeNumbers[1] = true;
	for (int i = 2; i < 707; i++)
	{
		if (notPrimeNumbers[i])
		{
			continue;
		}
		for (int j = i * i; j < 500001; j += i)
		{
			//�Ҽ��� �ƴ� ���� true�� �ٲ��ֱ�
			notPrimeNumbers[j] = true;
		}
	}

	std::cin >> candyCount;
	while (candyCount--)
	{
		int temp;
		std::cin >> temp;
		prices[temp]++; //�ش� ������ �� +1 ����
	}

	for (int i = 10000; i > 0; i--)
	{
		vector<int> temp;
		int p = 0;
		int &pCount = prices[i];
		while (pCount--)
		{
			p += i;
			temp.emplace_back(p);
		}
		if (temp.empty()) 
		{
			continue;
		}
		for (int j = 500000; j > 0; j--)
		{
			for (auto t : temp)
			{
				if (j - t < 0)
				{
					break;
				}
				countArr[j] += countArr[j - t];
			}
		}
	}


	long long result = 0;
	for (int i = 2; i < 500000; i++)
	{
		if (notPrimeNumbers[i])
		{
			continue;
		}
		result += countArr[i];
	}

	std::cout << result * (prices[0] + 1);
	return 0;
}