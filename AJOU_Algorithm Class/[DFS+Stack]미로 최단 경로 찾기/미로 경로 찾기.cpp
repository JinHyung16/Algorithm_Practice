#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int X, Y;
vector<vector<char>> miro;
vector<vector<int>> miroPos(2, vector<int>(2, 0)); //miro의 주어진 조건들 저장
vector<vector<bool>> visited(10000, vector<bool>(10000, false));

//up right down left 순으로 살펴본다
vector<int> dx = { 0, 1, 0, -1 };
vector<int> dy = { -1, 0, 1, 0 };

bool IsNotMiro = false;

void FileInput()
{
	//처음 파일을 열어 숫자를 읽어서 저장해둔다

	ifstream file("miro.txt");
	vector<int> numVec; //index 0~1은 row, col size의미 index 2~3은 시작점 x,y 좌표를 4~5는 도착지점 x,y 좌표 의미
	if (file.is_open())
	{
		int num = 0;
		string read;
		while (getline(file, read))
		{
			stringstream ss(read);
			if (read.find("*") == string::npos)
			{
				string result;
				while (getline(ss, result, ' '))
				{
					numVec.push_back(stoi(result.c_str()));
				}
			}
		}
	}
	else
	{
		std::cout << "find not file" << std::endl;
	}
	file.close(); //파일 닫기

	//미로 X, Y Size읽어오기
	X = numVec[0];
	Y = numVec[1];

	//미로 시작지점과 x좌표 y좌표 순으로 읽어오기
	miroPos[0][0] = numVec[2];
	miroPos[0][1] = numVec[3];

	//미로 끝 지점 x좌표 y좌표 순으로 읽어오기
	miroPos[1][0] = numVec[4];
	miroPos[1][1] = numVec[5];

	//미로 읽기
	file.open("miro.txt");
	vector<vector<char>> temp(Y);
	if (file.is_open())
	{
		string read;
		int index = 0;
		while (getline(file, read))
		{
			for (char& c : read)
			{
				if (index != 0 && index < (Y + 1))
				{
					//입력의 0번째와 마지막은 숫자로 이 부분을 제외한 나머지가 미로 본체
					if (c == '*' || c == ' ')
					{
						temp[index - 1].push_back(c);
					}
				}
			}
			index++;
		}
	}
	else
	{
		std::cout << "find not file" << std::endl;
	}
	file.close(); //파일 닫기

	//miro에 temp넣어서 미로 복사 끝
	miro = temp;

	numVec.clear();
	temp.clear();
}

void FindPath(int sx, int sy, int ex, int ey)
{	
	miro[sy][sx] = 'x'; //처음 위치는 이미 방문한곳으로 체킹
	miro[ey][ex] = ' '; //도착점 -2

	stack <pair<int, int>> stk; //지나간 길 stack에 넣어둠
	stk.push(make_pair(sx, sy));

	int curX = stk.top().first;
	int curY = stk.top().second;

	while (true)
	{
		miro[curY][curX] = 'x';
		if (miro[curY][curX] == miro[ey][ex])
		{
			break;
		}

		bool isMove = false; //4방향 중 전진에 성공했는지 체크
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if ((0 < nextX) && (nextX < X) && (0 < nextY) && (nextY < Y)
				&& miro[nextY][nextX] != '*')
			{
				if ((miro[nextY][nextX] == ' ' || miro[nextY][nextX] == 'e') && !visited[nextY][nextX])
				{
					stk.push({ nextX, nextY });
					curX = nextX;
					curY = nextY;
					isMove = true;
					visited[nextY][nextX] = true;

					break;
				}
			}
		}

		if (isMove == false)
		{
			miro[curY][curX] = 'o';
			if (stk.empty())
			{
				IsNotMiro = true;
				break;
			}
			stk.pop();
			curX = stk.top().first;
			curY = stk.top().second;
			IsNotMiro = false;
		}
	}
}


int main(void)
{
	FileInput();

	std::cout << "시작 지점: " << miroPos[0][0] << "," << miroPos[0][1]
		<< "도착 지점: " << miroPos[1][0] << "," << miroPos[1][1] << std::endl;
	/*
	std::cout << "-----------초기 미로 상태--------------" << std::endl;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			std::cout << miro[i][j];
		}
		std::cout << std::endl;
	}
	*/

	int startX = miroPos[0][0];
	int startY = miroPos[0][1];
	int endX = miroPos[1][0];
	int endY = miroPos[1][1];

	int pathCount = 0;

	FindPath(startX, startY, endX, endY);
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (miro[i][j] == 'o')
			{
				miro[i][j] = ' ';
			}
			else if (miro[i][j] == 'x')
			{
				pathCount++;
			}
		}
	}

	std::cout << "---------------움직인 경로 그리기---------------" << std::endl;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			std::cout << miro[i][j];
		}
		std::cout << std::endl;
	}
	
	if (IsNotMiro)
	{
		std::cout << "Path not found" << std::endl;
	}
	else
	{
		std::cout << "최소 움직인 거리: " << pathCount << std::endl;
	}
	return 0;
}
