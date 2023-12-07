#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze3 우유 축제 - Greedy 알고리즘
/// 0 = 딸기우유, 1 = 초코우유, 2 = 바나나우유
/// 무조건 순서는 0->1->2로 마셔야한다.
/// curMilk 변수를 선언한다.
/// 이는 가게에 따른 우유 정보를 담은 배열과 비교하며
/// 같다면 우유를 마신것으로 취급하고 같이 1씩 증가시킨다.
/// </summary>

int main(void)
{
	FastIO;
	
	int N = 0; // 우유 가게의 수 N
	cin >> N;
	vector<int> milk(N, 0);
	int curMilk = 0, result = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> milk[i];
	}

	for (int i = 0; i < milk.size(); i++)
	{
		if (milk[i] == curMilk)
		{
			curMilk++;
			result++;

			if (2 < curMilk)
			{
				curMilk = 0;
			}
		}
	}

	cout << result << "\n";
	return 0;
}