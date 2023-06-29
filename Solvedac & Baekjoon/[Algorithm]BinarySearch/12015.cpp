#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold2 가장 긴 증가하는 부분 수열 2 - 이분 탐색 알고리즘
/// lower_bound의 개념을 활용해 해결한다.
/// lower_bound는 이진 탐색으로 원소를 탐색하는데 찾으려는 key값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾을 때 쓴다.
/// 먼저 sequence 벡터를 만들고, std::cin >> a를 통해 값을 입력 받는다.
/// 1) sequence.empty() || sequence.back() < a 면 sequence.push_back(a)를 통해 값을 넣는다.
/// 2) sequence에 값이 있는데 sequence.back() > a면 lower_bound를 통해 a값보다 작거나 같은 값이 어디에 있는지 꺼내오고 해당 위치의 값을 a로 바꾼다.
/// 2-1) lower_bound(sequence.begin(), sequence.end(), a) - sequence.begin();을 통해 index 값을 구한다.
/// 
/// ex) N = 6, A = {10, 20, 30, 25, 15, 60} 일 때, 가장 긴 중가하는 부분 수열을 찾는 방법은 다음과 같다.
/// 1) sequence = {10, 20, 30}인 상황에서 25가 들어오면
/// 2) sequence.back() = 30 > 25 이므로
/// 3) lower_bound를 통해 25보다 같거나 큰 숫자가 배열 몇 번 째에 처음 나오는지 반환후 빈 변수에 저장 ->int index = 2;
/// 4) sequence[index] = 25로 바꾸기.
/// </summary>

using namespace std;

vector<int> sequence;

int main(void)
{
	FastIO;

	int N = 0; //수열 A의 크기 N

	std::cin >> N;
	for(int i = 0; i < N; i++)
	{
		int a = 0;
		std::cin >> a;
		if(sequence.empty() || sequence.back() < a)
		{
			sequence.push_back(a);
		}
		else
		{
			int index = std::lower_bound(sequence.begin(), sequence.end(), a) - sequence.begin();
			sequence[index] = a;
		}
	}

	std::cout << sequence.size() << "\n";
	return 0;
}