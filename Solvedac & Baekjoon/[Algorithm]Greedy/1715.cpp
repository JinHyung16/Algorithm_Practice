#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 카드 정렬하기 - Greedy 알고리즘
/// 오름차순으로 정렬된 카드가 들어오니, 들어올때마다 작은 크기끼리 묶어서 계속 더해나간다.
/// 문제는 더한 값을 다시 넣고 오름차순 정렬해야하는데, 매번 정렬을 실행하기에 우선순위 큐를 이용해보자
/// priority_queue는 정렬 기능이 들어간 queue로 매번 정렬을 하는거보단, 알아서 해주는게 좋다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //숫자 카드 묶음의 개수
	std::cin >> N;

	int numOne(0), numTwo(0);
	int minCompareCnt(0);

	//<자료형, 구현체, 비교 연산자> 이렇게 넣으면 된다.
	priority_queue<int, vector<int>, std::greater<int>> cardCompareQueue;
	for (int i = 0; i < N; i++)
	{
		int input;
		std::cin >> input;
		cardCompareQueue.push(input);
	}

	while (cardCompareQueue.size() > 1)
	{
		//priority_queue에서 제일 위(가장 작은 수) 두개를 꺼내고 priority_queue에서 지운다
		numOne = cardCompareQueue.top();
		cardCompareQueue.pop();
		numTwo = cardCompareQueue.top();
		cardCompareQueue.pop();

		//꺼낸 두 수를 더해서 최소 비교 횟수에 넣는다. 이때 minCompareCnt는 이전 본인의 값을 다음 계산에 사용해서 더한다
		minCompareCnt += (numOne + numTwo);

		//priority_queue의 꺼낸 두 수의 합을 넣는다.
		cardCompareQueue.push(numOne + numTwo);
	}

	std::cout << minCompareCnt << "\n";

	return 0;
}