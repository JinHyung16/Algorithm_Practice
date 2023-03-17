#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 영화감독 숌 - 브루트포스 알고리즘
/// 처음에 단순히 666을 붙여서 출력했다. 그러나 예제 출력을 보면 그렇게 하면 안된다.
/// 따라서 666이 들어간 숫자는 1000으로 나눠 나머지가 666이면 출력하면된다.
/// 이때 movieTitle은 영화 제목을, endCnt는 현재 몇 번째 종말의 수인지를 저장한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0);
	std::cin >> N;

	int endNum = 666;
	int movieTitle(0), endCnt(0);
	int temp(0);
	while(endCnt != N)
	{
		movieTitle++;
		temp = movieTitle;
		while (temp != 0)
		{
			if (temp % 1000 == endNum)
			{
				endCnt++;
				break;
			}
			else
			{
				temp /= 10;
			}
		}
	}

	std::cout << movieTitle << "\n";
	return 0;
}