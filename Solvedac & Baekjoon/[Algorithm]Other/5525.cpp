#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 IOIOI - 문자열 알고리즘
/// PN은 결국 IOI의 개수를 의미한다.
/// 따라서 문자열에서 IOI의 개수를 파악하면된다.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	
	int N(0), M(0); //문자열 개수 N, 문자열 길이 M
	string input;
	
	std::cin >> N;
	std::cin >> M;
	std::cin >> input;

	int result(0);
	for (int i = 0; i < M; i++)
	{
		int ioiLength(0);
		if (input[i] == 'I')
		{
			while (input[i + 1] == 'O' && input[i + 2] == 'I')
			{
				i += 2; //i기준 2칸 더 가서 봐야한다. 그래야 IOI로 확인한것
				ioiLength++;			
				if (ioiLength == N)
				{
					ioiLength--; //그래야 다음 IOI체크때 증가시킬 수 있음
					result++;
				}
			}
		}
	}

	std::cout << result << "\n";
	return 0;
}