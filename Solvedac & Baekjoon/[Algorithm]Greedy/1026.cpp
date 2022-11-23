#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver4 - 그리디 알고리즘
/// S = aVec[0]*bVec[0] + ... + aVec[n]*bVec[n] 일 때
/// aVec만 재배열하여 최소인 S 찾기
/// aVec을 오름차순해서 사실상 bVec의 가장 큰 값을 찾아 mapping하는 것이다
/// bVec을 내림차순하고 오름차순한 aVec의 값을 곱한다면 최소 S가 되는 것
/// </summary>


int main(void)
{
	int n(0);

	cin >> n;

	vector<int> aVec(n);
	vector<int> bVec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> aVec[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> bVec[i];
	}

	std::sort(aVec.begin(), aVec.end());
	std::sort(bVec.rbegin(), bVec.rend());

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (aVec[i] * bVec[i]);
	}

	std::cout << sum << std::endl;

	return 0;
}