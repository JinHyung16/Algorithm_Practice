#include<iostream>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 조별과제를 하려는데 조장이 사라졌다. - 수학 알고리즘
/// 성우는 1에서 5까지 이동 가능하다.
/// 성우가 민건이까지 가는데 가장 적은 시간으로 이동하려면
/// 결국 5씩 이동 가능하다면 5씩 이동해야한다.
/// 그렇지 않다면 가능한 5씩 이동하다 남은 거리를 해당 숫자에 맞춰 이동하면 된다.
/// 따라서 주어진 L을 기준으로 5로 딱 나눠 떨어질 때와 아닐때로 구분한다.
/// </summary>

int main(void)
{
	FastIO;
	
	int L = 0; // 성우와 민건이 집까지 거리

	cin >> L;

	if (L % 5 == 0)
	{
		cout << (L / 5) << "\n";
	}
	else
	{
		cout << (L / 5) + 1 << "\n"; // +1 하는 이유는 5씩 다 이동하고 남은 숫자는 1~4중 하나이므로 1번 이동하면 되므로
	}
	return 0;
}