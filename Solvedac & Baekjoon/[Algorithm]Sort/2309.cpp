#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 일곱 난쟁이 - 정렬 알고리즘
/// 7명의 난쟁이를 찾아 오름차순 정렬하여 출력해야 하는데, 조건은 7명의 키의 합이 100이여야한다.
/// 1. 처음 9명 키를 입력받으면서 전체 키 합을 total에 저장해두고 문제에 접근한다.
/// 2. 9명의 키를 입력받은 vector를 오름차순으로 sort한다.
/// 이중 for문을 통해 오름차순하여 정렬해둔 벡터에서 연달이 있는 두개의 키를 total에서 빼면서 100이랑 똑같아질 때, 그 때 index값을 제외하고 나머지 7명 키를 출력
/// 그리고 나서 return0으로 종료한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	vector<int> dwarfs(9, 0);
	int totalHeight = 0;

	for (int i = 0; i < dwarfs.size(); i++)
	{
		std::cin >> dwarfs[i];
		totalHeight += dwarfs[i];
	}

	std::sort(dwarfs.begin(), dwarfs.end());

	for (int i = 0; i < 8; i++) //먼저 탐색을 시작할 index이므로 마지막까지 돌 필요 없다.
	{
		for (int j = i + 1; j < 9; j++) //그 다음으로 연달아 탐색할 index로 i+1부터 항상 시작해 마지막까지 탐색한다.
		{
			if (totalHeight - dwarfs[i] - dwarfs[j] == 100)
			{
				for (int index = 0; index < 9; index++)
				{
					if (index == i || index == j)
					{
						continue;
					}
					std::cout << dwarfs[index] << "\n";
				}
				return 0; //break를 쓰면 바깥 for문은 못 나가므로 return0으로 프로그램을 끝내자.
			}
		}
	}
	return 0;
}
