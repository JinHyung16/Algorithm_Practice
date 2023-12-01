#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze1 약수들의 합 - 수학 알고리즘
/// 약수들을 찾은 뒤 조건에 맞춰 출력한다.
/// </summary>

int main(void)
{
	FastIO;

	while (true)
	{
		int n = 0;
		cin >> n;
		vector<int> num;
		int sum = 0;
		if (n == -1)
			break;
		for (int i = 1; i < n; i++)
		{
			if (n % i == 0)
				num.push_back(i);
		}
		for (int i = 0; i < num.size(); i++)
		{
			sum += num[i];
		}

		if (n == sum)
		{
			cout << n << " = ";
			for (int i = 0; i < num.size(); i++)
			{
				if (i == num.size() - 1)
				{
					cout << num[i];
				}
				else
				{
					cout << num[i] << " + ";
				}
			}
			cout << "\n";
		}
		else
		{
			cout << n << " is NOT perfect." << "\n";
		}
	}
	return 0;
}