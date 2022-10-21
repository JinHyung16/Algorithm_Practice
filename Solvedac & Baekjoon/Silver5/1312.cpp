#include<iostream>

using namespace std;

int main(void)
{
	//a는 분자, b는 분모, n은 a/b 나머지의 n번째 자리수 의미
	//ex)n=1, 3/4 = 0.75 -> 출력값은 7을 의미
	int a = 0, b = 0, n = 0;
	int result = 0;
	
	cin >> a >> b >> n;

	if (a % b == 0)
	{
		cout << 0;
		return 0;
	}

	if (a > b)
	{
		a %= b;
	}

	for (int i = 0; i < n; i++)
	{
		a *= 10;
		result = (int)(a / b);
		a %= b;
		
	}
	cout << result;

	return 0;
}