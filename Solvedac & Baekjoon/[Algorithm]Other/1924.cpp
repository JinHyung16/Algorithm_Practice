#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 2007년 - 수학 알고리즘
/// 입력된 x월 y일을 받는다.
/// 그리고 x월에서 1월씩 감소하면서 해당 x값에 맞춰 y에는 반대로 요일을 더한다.
/// 이렇게 x가 1보다 클때까지 반복하여 최종 다 더해진 y값을 찾고
/// y & 7한 값을 day를 저장한 vector의 index로 사용해 출력한다.
/// 이때, 먼저 월을 감소시켜야 하는데, 9월 2일의 경우 실제로 9월을 다 가지 않았기에 먼저 x를 감소시키고 y에 감소시킨 x에 해당하는 값을 더해야한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int x(0), y(0); //x월 y일
	std::cin >> x >> y;

	vector<string> dayVec = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	while (1 < x)
	{
		x--; //먼저 월을 감소시켜야한다.
		if (x == 2)
		{
			y += 28;
		}
		else if (x == 4 || x == 6 || x == 9 || x == 11)
		{
			y += 30;
		}
		else
		{
			y += 31;
		}
	}
	
	y %= 7;
	
	std::cout << dayVec[y] << "\n";
	return 0;
}
