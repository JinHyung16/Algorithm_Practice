#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<set>

/// <summary>
/// Gold3 교환 - Graph 알고리즘
/// BFS를 이용한 해결
/// 두 자릿 수 가 아니지만 1의 자리가 0인경우 체크
/// 기존엔 queue와 pair를 통해 key,value로 저장했으나,
/// 지금의 경우 value는 사용하지 않아 set이용
/// </summary>

using namespace std;

string n; // 정수 N
int k(0); // 연산 횟수 k
int maxNum(0); // k번 연산 후 나온 최대 정수

bool CheckDigitsOFOne()
{
	int digitCnt(0);
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] > '0')
		{
			digitCnt++;
		}
	}

	if (digitCnt > 1)
	{
		return true;
	}
	return false;
}

void BFS()
{
	queue<string> q;
	q.push(n);

	for (int a = 0; a < k; a++)
	{
		int qSize = q.size();
		set<string> visited;

		for (int b = 0; b < qSize; b++)
		{
			string temp = q.front();
			q.pop();

			for (int i = 0; i < temp.size() - 1; i++)
			{
				for (int j = i + 1; j < temp.size(); j++)
				{
					if (i == 0 && temp[j] == '0')
					{
						continue;
					}

					std::swap(temp[i], temp[j]);
					if (visited.find(temp) == visited.end())
					{
						if (a == k - 1)
						{
							//마지막 k번 수행중이라면
							int value = std::stoi(temp);
							maxNum = std::max(maxNum, value);
						}
						q.push(temp);
						visited.insert(temp);
					}
					std::swap(temp[i], temp[j]);
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> k;
	if (n.size() == 1)
	{
		//한 자릿 수의 경우 연산할 수 없음
		std::cout << -1 << std::endl;
		return 0;
	}
	else if (n.size() == 2 && !CheckDigitsOFOne())
	{
		std::cout << -1 << std::endl;
		return 0;
	}

	BFS();

	std::cout << maxNum << std::endl;

	return 0;
}