#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 누울 자리를 찾아라 - 문자열 알고리즘
/// string으로 방을 한줄씩(가로의미) 입력받아 char 타입의 vector에 넣는다.
/// 이때 넣으면서 가로로 누울 수 있는 공간을 같이 찾아가는게 포인트
/// 그 후 맵을 다 넣었으면 세로로 누울 수 있는 공간을 찾아간다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //방의 크기 N
	string roomInput; //방
	int rowCnt(0), colCnt(0), emptyCnt(0);
	vector<vector<char>> room(101, vector<char>(101, ' '));

	std::cin >> N;
	//초기 방 상태를 한줄씩 입력받는다
	//입력 받으면서 가로로 누울 수 있는 공간도 같이 찾아간다.
	for (int i = 0; i < N; i++)
	{
		std::cin >> roomInput;
		emptyCnt = 0;
		for (int j = 0; j < roomInput.size(); j++)
		{
			room[i][j] = roomInput[j];
			if (room[i][j] == '.')
			{
				//빈 공간이면
				emptyCnt++;
			}
			else
			{
				//room[i][j] == 'X' 즉 짐을 만났다면
				if (2 <= emptyCnt)
				{
					colCnt++;
				}
				emptyCnt = 0;
			}
		}
		//벽을 만났을 때
		if (2 <= emptyCnt)
		{	
			colCnt++;
		}
	}

	//세로로 누울 수 있는 공간을 찾는다.
	for (int i = 0; i < N; i++) {
		emptyCnt = 0;
		for (int j = 0; j < N; j++) {
			if (room[j][i] == '.')
			{
				emptyCnt++;
			}
			else 
			{
				//room[i][j] == 'X' 즉 짐을 만났다면
				if (2 <= emptyCnt)
				{
					rowCnt++;
				}
				emptyCnt = 0;
			}
		}
		//벽을 만났을 때
		if (2 <= emptyCnt)
		{
			rowCnt++;
		}
	}

	cout << colCnt << " " << rowCnt << "\n";

	return 0;
}