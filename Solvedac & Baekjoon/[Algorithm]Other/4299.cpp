#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 AFC 윔블던- 구현 알고리즘
/// 두 팀을 A, B라 가정한다.
/// 두 팀 스코어 합을 x, 차를 y라 가정하면
/// a = (x+y) / 2, b = (x-y) / 2 
/// 왜냐면 연립 방정식을 생각하면 된다.
/// </summary>


int main(void)
{
	FastIO;
	
	int sum = 0, dif = 0;
	cin >> sum >> dif;

	int a = 0, b = 0;

	if ( sum < dif )
		cout << -1 << "\n";
	else
	{
		a = (sum + dif) / 2;
		b = (sum - dif) / 2;
		if ( a + b == sum && a - b == dif )
			cout << a << " " << b;
		else
			cout << "-1";
	}

	return 0;
}