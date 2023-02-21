#include<iostream>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 수 찾기 - 자료 구조 알고리즘
/// for문으로 다 찾으려면 최악 O(N^2)이므로
/// 무언가를 찾을땐 O(logN)인 Binary Search를 이용하자
/// Binary Search진행 전 항상 오름차순으로 정렬해놓고 해야한다.
/// 아니면 제공하는 binary_search함수를 사용해서 해결해도 된다.
/// main에서 배열을 너무 크게 할당하면 stack에 저장되기에 heap에 저장할 수 있도록 글로벌로 선언했다.
/// </summary>

using namespace std;

int N(0), M(0); //N개의 정수, M개의 주어진 수들
int arrayN[100001];


void My_BinarySearch(int num, int numArr[])
{
	int left = 0;
	int right = N - 1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (numArr[mid] == num)
		{
			std::cout << "1 " << "\n";
			return;
		}
		else if (numArr[mid] < num)
		{
			//왼쪽에서 우측(중앙 쪽)으로 한칸 이동
			left = (mid + 1);
		}
		else if (num < numArr[mid])
		{
			//오른쪽에서 좌측(중앙 쪽)으로 한칸 이동
			right = (mid - 1);
		}
	}
	std::cout << "0" << "\n";
	return;
}

int main(void)
{
	FastIO;

	int input(0);

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> input;
		arrayN[i] = input;
	}
	
	//오름차순 정렬
	std::sort(arrayN, arrayN + N);

	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		std::cin >> input;
		My_BinarySearch(input, arrayN);

		//algorithm에서 제공하는 binary_search 함수사용시 vector이용해도 된다.
		//std::binary_search(vector.begin(), vector.end(), input);
	}

	return 0;
}