#include<iostream>
#include<vector>
#include<set>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver5 중복 빼고 정렬하기 - 정렬 알고리즘
/// set을 이용해 중복 없이 입력 받는다.
/// 그리고 출력시 set<int>::iterator iter;를 이용해
/// set.begin()부터 iter != set.end()까지 출력한다.
/// set.end()는 마지막 원소의 그 다음을 가리키므로 이렇게 해야한다.
/// </summary>



int main(void)
{
	FastIO;

	int N = 0; // N개의 정수
	cin >> N;
	set<int> setNums;

	int input = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		setNums.insert(input);
	}

	set<int>::iterator iter;
	for (iter = setNums.begin(); iter != setNums.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << "\n";
	return 0;
}