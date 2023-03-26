#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>?


#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 리모컨 - 브루트포스 알고리즘
/// 버튼 0~9까지의 개수만큼 배열을 만들어 미리 고장난 버튼을 체크해둔다.
/// 그리고 채널 시작부터 100까지의 차이를 최소 움직인 횟수에 저장해두고
/// 0번부터 채널 최대까지 올렸을때와, 채널 최대부터 0번까지 내려올때 각 채널별 움직이는 최소 횟수를 저장한다.
/// 이때 N의 최대 범위가 500000이므로 오르고 내려오려면 for문은 500000 * 2만큼 움직여야한다.
/// 그렇게 해당 i(채널 값)을 btn에서 누를 수 있는지 없는지 판단하면서 minMove를 갱신해간다.
/// 
/// string의 index하나는 char type으로 char '0'은 숫자로 48이다.
/// </summary>

using namespace std;

//0~9까지 버튼들 활성화 상태 분류
vector<bool> btnInteractive(10, true);
int startChannel = 100; //초기 시작은 100번에서

bool CheckButton(int curBtn)
{
	string btn = std::to_string(curBtn);
	for (int i = 0; i < btn.length(); i++)
	{
		int btnNum = btn[i] - 48;
		if (!btnInteractive[btnNum])
		{
			return false;
		}
	}
	return true;
}
int main(void)
{
	FastIO;

	int N(0), M(0); //이동하려는 채널 N, 고장난 버튼 개수 M
	std::cin >> N;
	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		std::cin >> temp;
		btnInteractive[temp] = false;
	}

	int minMoveChannel = std::abs(N - startChannel); //목표 채널과 시작 채널의 차이를 담아둔다.
	
	for (int i = 0; i <= 1000000; i++)
	{
		if (CheckButton(i))
		{
			int curChannel = std::abs(N - i) + std::to_string(i).length();
			minMoveChannel = std::min(minMoveChannel, curChannel);
		}
	}

	std::cout << minMoveChannel << "\n";
	return 0;
}