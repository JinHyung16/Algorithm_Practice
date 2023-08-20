#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 �ﰢ�� �ܿ�� - ������ �˰���
/// ���� ���ǿ� ���� if���� �����.
/// �� �� �ش� ���ǿ� �´� ���� vector<string>���� ���� �д´�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int angleA = 0, angleB = 0, angleC = 0; //�� ���� ũ��
	vector<string> triangle = { "Equilateral", "Isosceles", "Scalene", "Error" };
	std::cin >> angleA >> angleB >> angleC;
	if ( angleA == angleB && angleB == angleC )
	{
		std::cout << triangle[0] << "\n";
	}
	else if ( angleA + angleB + angleC == 180 && (angleA == angleB || angleB == angleC || angleA == angleC))
	{
		std::cout << triangle[1] << "\n";
	}
	else if ( angleA + angleB + angleC == 180 && angleA != angleB && angleB != angleC)
	{
		std::cout << triangle[2] << "\n";
	}
	else if ( angleA + angleB + angleC != 180 )
	{
		std::cout << triangle[3] << "\n";
	}

	return 0;
}