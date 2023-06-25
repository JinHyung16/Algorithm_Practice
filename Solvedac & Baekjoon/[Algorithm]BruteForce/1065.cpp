#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 한수 - 브루트포스 알고리즘
/// 1부터 N까지 각 자리수 값을 다 1의 자리 숫자로 바꾼 뒤, 차이를 이용해 같은지 비교한다.
/// N이 100 미만이면 한수는 해당 N만큼 있는거니 N이 100 이상일때에 대해서 생각한다.
/// 
/// N이 100 미만이면 출력은 N의 값을 그대로 한다.
/// N이 100 이상일 땐 2중 for문을 통해 100부터 N까지 반복하면서
/// 안쪽 for문에선 바깥쪽 for문의 현재 값을 string으로 바꿔 해당 길이만큼 돌면서 한수 조건을 만족하는지 아닌지 판단해
/// 만족한다면 result를 증가시키면서 간다.
/// 
/// 이때 result는 99로 초기화 해두는데, 이유는 N이 100 미만일때 한수의 최대 개수는 99이기 때문이다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	string input;
	std::cin >> input;

	int n = std::stoi(input);

	int result = 99;
	for(int i = 100; i <= n; i++)
	{
		string temp = std::to_string(i);
		bool isHanso = true;
		for(int j = 1; j < temp.size() - 1; j++)
		{
			if(temp[j] - temp[j-1] != temp[j+1] - temp[j])
			{
				isHanso = false;
			}
		}
		if(isHanso)
		{
			result ++;
		}
	}

	if(n < 100)
	{
		std::cout << n << "\n";
		return 0;
	}
	std::cout << result << "\n";
	return 0;
}