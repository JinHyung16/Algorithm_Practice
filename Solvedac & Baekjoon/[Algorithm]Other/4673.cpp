#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 셀프 넘버 - 수학 알고리즘
/// n에 대하여 n + (n의 각 자릿수)를 하면서 나온 결과를 n이 0이 될때까지 반복하여 나온 수들은 n에 대한 생성자들로 셀프넘이 아니다.
/// 이를 체크하여 vector에 self num이 아닌걸 false로 두고 마지막에 최종적으로 true것들만 출력한다.
/// </summary>

using namespace std;


int NotSelfNumCheck(int num)
{
	int n = num;
	while (num != 0)
	{
		n += (num % 10);
		num /= 10;
	}
	return n;
}

int main(void)
{
	FastIO;
	
	vector<bool> selfNumVec(10001, true);
	
	for (int i = 1; i <= 10000; i++)
	{
		int notSelfNum = NotSelfNumCheck(i);
		if (notSelfNum <= 10000)
		{
			selfNumVec[notSelfNum] = false;
		}
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (selfNumVec[i])
		{
			std::cout << i << "\n";
		}
	}
	return 0;
}
