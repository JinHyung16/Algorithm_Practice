#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 특별한 날 - 구현 알고리즘
/// </summary>


int main(void)
{
	FastIO;

	int month = 0, day = 0;
	cin >> month;
	cin >> day;

	if ( month == 2 )
	{
		if ( day == 18 )
			cout << "Special" << "\n";
		else if ( 18 < day )
			cout << "After" << "\n";
		else
			cout << "Before" << "\n";
	}
	else if ( 2 < month )
		cout << "After" << "\n";
	else
		cout << "Before" << "\n";

	return 0;
}