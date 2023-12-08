#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver4 주몽 - Sort 알고리즘
/// 두 포인터를 이용해 문제를 해결해야한다.
/// 두 포인터를 이용할 때 배열은 정렬되어 있어야 한다.
/// </summary>

int main(void)
{
	FastIO;

	int N = 0, M = 0; // 재료의 개수 N, 갑옷 만드는 필요한 수 M
	cin >> N;
	cin >> M;
	vector<int> matter(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> matter[i];
	}
	sort(matter.begin(), matter.end());

	int start = 0, end = N - 1, cnt = 0;
	while (start < end)
	{
		int sum = matter[start] + matter[end];
		if (sum == M)
		{
			cnt++;
			start++;
			end--;
		}
		else if (sum < M)
		{
			start++;
		}
		else
		{
			end--;
		}
	}

	cout << cnt << "\n";
	return 0;
}