#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 쿼드트리 - 분할 정복 알고리즘
/// 4개의 구역으로 나눌때, 배열 크기 n/2를 하여 나눈다.
/// 왜냐면 N은 2의 제곱으로 주어지기 때문이다.
/// 문제 입력이 공백없이 들어온다. 따라서 char로 받아서 문제를 해결하자
/// 처음에 이걸 모르고 int로 했다가, 입력후 출력이 안되어서 당황했다.
/// </summary>

using namespace std;

vector<vector<char>> map(64, vector<char>(64, 0));
vector<char> result;

void DivideMap(int x, int y, int n)
{
	char start = map[y][x];
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (start != map[i][j])
			{
				result.push_back('(');
				//제1,2,3,4사분면 순서대로 반복한다.
				DivideMap(x, y, n / 2);
				DivideMap(x + (n / 2), y, n / 2);
				DivideMap(x, y + (n / 2), n / 2);
				DivideMap(x + (n / 2), y + (n / 2), n / 2);
				result.push_back(')');
				return;
			}
		}
	}
	result.push_back(start);
}

int main(void)
{
	FastIO;
	
	int N(0); //영상의 크기 N
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> map[i][j];
		}
	}

	DivideMap(0, 0, N);
	
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i];
	}
	std::cout << "\n";
	return 0;
}