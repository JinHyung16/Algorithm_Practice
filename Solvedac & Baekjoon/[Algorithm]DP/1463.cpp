#include<iostream>
#include<vector>

using namespace std;

/*
* Silver3 - 1로 만들기
*/

int main(void)
{
	// 각 입력에 대해 연산의 최소를 찾는게 키 포인트, 입력을 x라고 하자
	// ex)2 입력시, 1)2나누고 +1 -> 연산 2번 / 2)3으로 나눈 나머지 -> 연산 1번
	// 2로 나눠 나머지 0인 경우 f(x)= 1 + f(x/2)
	// 3으로 나눠 나머지 0인 경우 f(x) = 1 + f(x/3)
	// 두 수 모두 나머지 발생하는 경우 f(x) = f(x-1) + 1
	// 왜 x/2, x/3이냐면 x가 input인데 이게 각 수로 나눠진다는건 배수를 의미하기 때문이다.
	
	// numVec은 연산 횟수 저장해놓은 것
	vector<int> numberVec(1000001, 0); //10^6 길이의 연산 횟수 다 0으로 초기화

	int number = 0;

	numberVec[0] = 1; //왜냐면 1이 되기위해선 +1 연산 한번 사용됨
	numberVec[1] = 0; //왜냐면 1은 연산 안해도 바로 1이니깐

	cin >> number;

	for (int i = 2; i <= number; i++)
	{
		numberVec[i] = numberVec[i - 1] + 1;
		if (i % 2 == 0)
		{
			numberVec[i] = min(numberVec[i], numberVec[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			numberVec[i] = min(numberVec[i], numberVec[i / 3] + 1);
		}
	}

	cout << numberVec[number];

	return 0;
}