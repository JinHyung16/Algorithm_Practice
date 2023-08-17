#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 생일 - 정렬 알고리즘
/// vector에 pair를 쓰면 최대 2개까지밖에 못 넣는다.
/// 따라서 vector<pair<pair<int,in>, pair<int, string>>>을 통해 생년,월,일, 이름 순서로 받는다.
/// 왜 이런 순서로 저장하냐면 년->월->일 순으로 sort하기 위해서다.
/// 
/// 문제에선 입력 순서가 이름, 일, 월, 년도니 vector의 순서를 잘 생각해서 넣자
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int n = 0; //반 학생의 수 n
	std::cin >> n;
	vector<pair<pair<int, int>, pair<int, string>>> students(n);

	for ( int i = 0; i < n; i++ )
	{
		std::cin >> students[i].second.second >> students[i].second.first >> students[i].first.second >> students[i].first.first;
	}

	std::sort(students.begin(), students.end());

	std::cout << students[n - 1].second.second << "\n" << students[0].second.second << "\n";
	return 0;
}