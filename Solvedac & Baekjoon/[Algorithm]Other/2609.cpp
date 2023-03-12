#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 최대공약수와 최소공배수 - 수학 알고리즘
/// 최대공약수는 유클리드 호제법으로 구하고 최소공배수는 최대 공약수를 이용하면 쉽게 구한다.
/// </summary>

using namespace std;

int GreatestCommonDivisor(int num1, int num2)
{
	int temp = num1 % num2;
	while (temp != 0)
	{
		num1 = num2;
		num2 = temp;
		temp = num1 % num2;
	}

	return num2;
}

int LeastCommonMultiple(int num1, int num2, int gcdNum)
{
	int multi = num1 * num2;
	return (multi / gcdNum);
}

int main(void)
{
	FastIO;

	int a(0), b(0);
	std::cin >> a >> b;
	int gcdNum = GreatestCommonDivisor(a, b);
	int lcmNum = LeastCommonMultiple(a, b, gcdNum);

	std::cout << gcdNum << "\n" << lcmNum << "\n";
	return 0;
}