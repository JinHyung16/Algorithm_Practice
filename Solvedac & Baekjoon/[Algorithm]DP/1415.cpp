#include<iostream>
#include<vector>

/// <summary>
/// Gold2 사탕 - DP 알고리즘
/// 사탕은 최대 50개, 가격은 최대 10000
/// bool type으로 소수가 아닌것들은 다 true로 바꿔주고 시작한다.
/// 받은 가격을 들고와서 해당 가격이 있는 곳에 값을 들고와 count배열에 저장
/// </summary>


using namespace std;

int prices[10001];
bool notPrimeNumbers[500001]; //소수인지 아닌지 담은 배열
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
			//소수가 아닌 곳은 true로 바꿔주기
			notPrimeNumbers[j] = true;
		}
	}

	std::cin >> candyCount;
	while (candyCount--)
	{
		int temp;
		std::cin >> temp;
		prices[temp]++; //해당 가격의 값 +1 증가
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