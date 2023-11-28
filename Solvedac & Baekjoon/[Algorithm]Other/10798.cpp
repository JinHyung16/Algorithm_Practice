#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze1 세로읽기 - 문자열 알고리즘
/// string을 이용해 한줄씩 입력 받는다.
/// 그 후 출력시 주의할 점은
/// 2중 for문과 string의 해당 인덱스의 문자가 있는지 없는지 검사하는 방법이다.
/// 15개의 문자를 5줄로 출력하니 이 순서대로 이중 for문을 돌고
/// 1줄씩 출력하는데 이때 해당 줄의 size가 i보다 크면 출력한다.
/// </summary>

int main(void)
{
	FastIO;

	int line = 5; //5줄 입력
	string input[5];

	for (int i = 0; i < line; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i < input[j].size())
			{
				cout << input[j][i];
			}
		}
	}
	return 0;
}