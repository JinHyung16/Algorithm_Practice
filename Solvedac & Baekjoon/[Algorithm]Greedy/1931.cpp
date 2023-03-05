#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 회의실 배정 - Greedy 알고리즘
/// 사용할 수 있는 회의의 수가 많아지려면 결국 끝나는 시간을 기준으로 반대로 채워나가면 된다.
/// 즉 회의 시간을 {start, end}순으로 넣었다면 내림차순 정렬을
/// {end, start}로 넣었다면 오름차순 정렬을 하여 끝나는 시간을 기준으로 정렬이 되게 바꾼다.
/// 
/// 틀렸던 구간)에 대한 반례
/// 즉 처음 회의에 대해서 한번 더 계산이 된다.
/// N=5 -> {2,2}, {3,2}, {4,2}, {5,1}, {1,7} 넣으면 5가 나온다.
/// 원래는 {5,1} -> {2,2} -> {3,2} -> {4,2} 이렇게 가능하므로 4가 나와야한다.
/// </summary>

using namespace std;

vector<pair<int, int>> meetingSchedule;

bool CompareEndTime(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(void)
{
	FastIO;
	
	int N(0); //회의의 수
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		std::cin >> start >> end;
		meetingSchedule.push_back(make_pair(start, end));
	}

	std::sort(meetingSchedule.begin(), meetingSchedule.end(), CompareEndTime);

	int time = meetingSchedule[0].second; //종료 시간이 가장 빠른 회의를 담는다.
	int meetingCnt(1);

	//틀렸던 구간) for문 시작을 0부터 했을 때 문제점이 생겼다.
	for (int i = 1; i < N; i++)
	{
		if (time <= meetingSchedule[i].first)
		{
			//두번째 회의의 시작 시간이 첫 번째 회의의 종료시점보다 크거나 같다면
			time = meetingSchedule[i].second;
			meetingCnt += 1;
		}
	}

	std::cout << meetingCnt << "\n";
	return 0;
}