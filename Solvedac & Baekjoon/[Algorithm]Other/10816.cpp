#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 숫자 카드 2 - 자료 구조 알고리즘
/// 오름차순으로 정렬한 뒤, binary search를 진행하면서 개수 count를 증가시키면 되지만,
/// 이 경우 배열의 크기가 갖다면, O(NM)으로 시간초과가 뜬다.
/// 따라서 Upper Bound와 Lower Bound를 이용해 해결한다.
/// lower_bound는 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에 있는지
/// upper_bound는 찾으려는 key값을 초과하는 숫자가 배열 몇 번째에 있는지 찾기 위함이다.
/// 사용 조건 역시 오름차순 되어 있어야 한다.
/// 
/// 주의)각 UpperBound, LowerBound 함수의 const vector<int>& vec으로 선언해서
/// 입력받은 값을 저장하는 cards와 checkList vector를 글로벌로 선언하지 않고 사용하려고 했으나,
/// 문제는 시간초과가 생겼다.
/// </summary>

using namespace std;

int N(0), M(0); //상근이가 갖고 있는 카드 N개, 갖고 있는지 확인할 카드 개수 M
vector<int> cards;
vector<int> checkList;
int UpperBound(int key)
{
	int left = 0, right = N;
	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (key < cards[mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	return right;
}

int LowerBound(int key)
{
	int left = 0; int right = N;
	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (key <= cards[mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	return right;
}

int main(void)
{
	FastIO;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		std::cin >> input;
		cards.push_back(input);
	}

	//오름차순 정렬
	std::sort(cards.begin(), cards.end());

	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		int input;
		std::cin >> input;
		checkList.push_back(input);
	}

	for (int i = 0; i < checkList.size(); i++)
	{
		std::cout << (UpperBound(checkList[i]) - LowerBound(checkList[i])) << " ";
	}
	std::cout << "\n";
	return 0;
}