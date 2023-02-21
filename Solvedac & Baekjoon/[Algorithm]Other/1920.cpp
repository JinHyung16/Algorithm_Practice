#include<iostream>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 �� ã�� - �ڷ� ���� �˰���
/// for������ �� ã������ �־� O(N^2)�̹Ƿ�
/// ���𰡸� ã���� O(logN)�� Binary Search�� �̿�����
/// Binary Search���� �� �׻� ������������ �����س��� �ؾ��Ѵ�.
/// �ƴϸ� �����ϴ� binary_search�Լ��� ����ؼ� �ذ��ص� �ȴ�.
/// main���� �迭�� �ʹ� ũ�� �Ҵ��ϸ� stack�� ����Ǳ⿡ heap�� ������ �� �ֵ��� �۷ι��� �����ߴ�.
/// </summary>

using namespace std;

int N(0), M(0); //N���� ����, M���� �־��� ����
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
			//���ʿ��� ����(�߾� ��)���� ��ĭ �̵�
			left = (mid + 1);
		}
		else if (num < numArr[mid])
		{
			//�����ʿ��� ����(�߾� ��)���� ��ĭ �̵�
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
	
	//�������� ����
	std::sort(arrayN, arrayN + N);

	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		std::cin >> input;
		My_BinarySearch(input, arrayN);

		//algorithm���� �����ϴ� binary_search �Լ����� vector�̿��ص� �ȴ�.
		//std::binary_search(vector.begin(), vector.end(), input);
	}

	return 0;
}