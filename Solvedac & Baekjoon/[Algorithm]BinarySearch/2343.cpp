#include<iostream>
#include<algorithm>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 기타 레슨 - 이분 탐색 알고리즘
/// 최소 녹화 시간은 1이고 최대는 N개 입력받은 시간들의 총합이다.
/// 따라서 1부터 high까지 이분 탐색을 시작한다.
/// 남은 블루레이 공간이 다음 강의를 모두 담지 못한다면 새 블루레이 사용
/// 남은 블루레이 공간을 블루레이 초기 크기로 바꾸면서 카운팅한다.
/// 그 후 남은 블루레이 공간에서 강의 시간만큼 빼준다.
/// 
/// 블루레이 개수가 M보다 크면 블루레이 초기 크기를 다시 늘려주고
/// 아니면 블루레이 크기 값을 저장 후 블루 레이 크기를 줄여 다시 탐색 시작
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, M = 0; //강의의 수 N과 M
	int low = 1, mid = 0, high = 0;
	int total = 0, result = 0;

	std::cin >> N >> M;
	vector<int> video(N, 0);
	for ( int i = 0; i < N; i++ )
	{
		int input = 0;
		std::cin >> input;
		video[i] = input;
		high += input;
	}
	
	while ( low <= high )
	{
		mid = (low + high) / 2;
		total = mid;
		bool canRecord = true;
		int cnt = 1; //블루레이 개수 1개
		for ( int i = 0; i < N; i++ )
		{
			if ( mid < video[i] )
			{
				canRecord = false;
				break;
			}
			if ( total < video[i] )
			{
				total = mid;
				cnt++; //새로운 블루레이 사용
			}
			total -= video[i];
		}
		if ( M < cnt || !canRecord )
		{
			low = mid + 1;
		}
		else if ( cnt <= M )
		{
			high = mid - 1;
			result = mid;
		}
	}
	std::cout << result << "\n";
	return 0;
}