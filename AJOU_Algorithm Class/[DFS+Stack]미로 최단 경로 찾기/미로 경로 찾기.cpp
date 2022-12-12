#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>
#include<algorithm>

using namespace std;


int X, Y;
vector<vector<char>> miro;
vector<vector<int>> miroPos(2, vector<int>(2, 0)); //miro의 주어진 조건들 저장

//(1,1)시작 기준 down->left->up->right 순으로 살펴본다
vector<int> dx = { 0, 1, 0, -1 };
vector<int> dy = { 1, 0, -1, 0 };

stack <pair<int, int>> pathStk; //지나간 길 stack에 넣어둠

void FileInput()
{
	//처음 파일을 열어 숫자를 읽어서 저장해둔다

	ifstream file("miro.txt");
	vector<int> numVec; //index 0~1은 row, col size의미 index 2~3은 시작점 x,y 좌표를 4~5는 도착지점 x,y 좌표 의미
	if (file.is_open())
	{
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
					temp[index - 1].push_back(c);
				}
			}
			index += 1;
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

void FindPath(const vector<vector<char>>& m, int sx, int sy, int ex, int ey)
{
	vector<vector<char>> maze = m;
	maze[sy][sx] = 'S'; //처음 위치는 이미 방문한곳으로 체킹
	maze[ey][ex] = 'E'; //도착점

	//stack <pair<int, int>> pathStk; //지나간 길 stack에 넣어둠
	pathStk.push(make_pair(sx, sy));

	int curX = pathStk.top().first;
	int curY = pathStk.top().second;

	while (true)
	{
		maze[curY][curX] = 'x';

		if (curY == ey && curX == ex)
		{
			maze[curY][curX] = 'x';
			//도착했다면
			std::cout << "미로 도착" << std::endl;
			break;
		}

		bool isMove = false; //4방향 중 전진에 성공했는지 체크
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if ((0 < nextX) && (nextX < X) && (0 < nextY) && (nextY < Y) && maze[nextY][nextX] != '*')
			{
				if (maze[nextY][nextX] == ' ' || maze[nextY][nextX] == 'E')
				{
					pathStk.push({ nextX, nextY });
					curX = nextX;
					curY = nextY;
					isMove = true;
					break;
				}
			}
		}

		if (isMove == false)
		{
			maze[curY][curX] = 'o';
			if (pathStk.empty())
			{
				break;
			}
			pathStk.pop();
			if (pathStk.size() > 0)
			{
				curX = pathStk.top().first;
				curY = pathStk.top().second;
			}
		}
	}
}


int main(void)
{
	FileInput();

	std::cout << "Row Size:" << Y << " Col Size:" << X << "\n" << "시작 지점:" << miroPos[0][0] << "," << miroPos[0][1]
		<< "도착 지점:" << miroPos[1][0] << "," << miroPos[1][1] << std::endl;

	std::cout << "-----------초기 미로 상태--------------" << std::endl;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			std::cout << miro[i][j];
		}
		std::cout << std::endl;
	}


	int startX = miroPos[0][0];
	int startY = miroPos[0][1];
	int endX = miroPos[1][0];
	int endY = miroPos[1][1];

	int pathCount = 0;

	FindPath(miro, startX, startY, endX, endY);

	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (miro[i][j] == 'x' || miro[i][j] == 'o')
			{
				miro[i][j] = ' ';
			}
		}
	}

	stack<pair<int, int>> stk;
	stk = pathStk;

	while (!stk.empty())
	{
		pathCount++;
		miro[stk.top().second][stk.top().first] = 'x';
		stk.pop();
	}

	std::cout << "---------------미로 돌고난 후---------------" << std::endl;

	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			std::cout << miro[i][j];
		}
		std::cout << std::endl;
	}
	if (pathStk.empty())
	{
		std::cout << "Path not found" << std::endl;
	}
	else
	{
		std::cout << "최소 움직인 거리: " << pathCount << std::endl;
	}
	return 0;
}
