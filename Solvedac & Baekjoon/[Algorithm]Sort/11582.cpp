#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver4 치킨 TOP N - 정렬 알고리즘
/// 분할정복과 정렬을 이용해야 하는데, 합병 정렬을 이용하면 된다.
/// MergeSort(int start, int end)는 쉽게 생각하면
/// main에서 0부터 N-1까지 인자를 전달하고
/// MergeSort에선 mid 즉 (start + end) / 2로 중앙값을 찾아
/// start ~ mid까지, mid + 1 ~ end까지 MergeSort를 재귀로 호출한다.
/// 그 후 마지막에 Merge를 통해 start ~ end까지를 합쳐주는 과정을 반복한다.
/// 
/// Merge과정이 복잡하다.
/// left는 start 위치부터 right는 mid + 1 위치부터 시작한다.
/// 이때 right가 왜 mid+1이냐 배열 A와 B가 있을 때 좌측값들을 정렬한 A 배열의 시작은 0번째 인덱스지만
/// 우측을 정렬한 B의 배열의 시작은 mid + 1부터기 때문이다. 즉 MergeSort할 때 좌측은 start부터 우측은 mid+1부터 시작했기 때문이다.
/// k는 빈 배열의 가장 작은 값은 index 순서대로 채울 값인데 start부터 시작한다.
/// while(k <= end)를 통해 배열의 모든 값을 채울 수 있게 한다.
/// </summary>


int N = 0, K = 0; //치킨집의 개수 N, 정렬중인 회원들의 수 K
vector<int> chicknes;
vector<int> temp;

void Merge(int start, int end)
{
	if (N / K < end - start) return;

	int mid = (start + end) / 2;
	int left = start, right = mid + 1, k = start;

	while (k <= end)
	{
		if (mid < left)
		{
			temp[k++] = chicknes[right++];
			continue;
		}
		if (end < right)
		{
			temp[k++] = chicknes[left++];
			continue;
		}
		if (chicknes[left] <= chicknes[right])
		{
			temp[k++] = chicknes[left++];
		}
		else
		{
			temp[k++] = chicknes[right++];
		}
	}
	for (int i = start; i <= end; i++)
	{
		chicknes[i] = temp[i];
	}
}

void MergeSort(int start, int end)
{
	if (end <= start) return;
	int mid = (start + end) / 2;
	MergeSort(start, mid);
	MergeSort(mid + 1, end);
	Merge(start, end);
}

int main(void)
{
	FastIO;

	int input = 0;

	cin >> N;
	temp.resize(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		chicknes.push_back(input);
	}
	cin >> K;

	MergeSort(0, N - 1);
	for (int i = 0; i < N; i++)
	{
		cout << chicknes[i] << " ";
	}
	cout << "\n";

	return 0;
}