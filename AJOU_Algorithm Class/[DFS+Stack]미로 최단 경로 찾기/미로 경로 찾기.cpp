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
vector<vector<int>> miroPos(2, vector<int>(2, 0)); //miro�� �־��� ���ǵ� ����
vector<vector<bool>> visited(10000, vector<bool>(10000, false));

//up right down left ������ ���캻��
vector<int> dx = { 0, 1, 0, -1 };
vector<int> dy = { -1, 0, 1, 0 };

bool IsNotMiro = false;

void FileInput()
{
	//ó�� ������ ���� ���ڸ� �о �����صд�

	ifstream file("miro.txt");
	vector<int> numVec; //index 0~1�� row, col size�ǹ� index 2~3�� ������ x,y ��ǥ�� 4~5�� �������� x,y ��ǥ �ǹ�
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
	file.close(); //���� �ݱ�

	//�̷� X, Y Size�о����
	X = numVec[0];
	Y = numVec[1];

	//�̷� ���������� x��ǥ y��ǥ ������ �о����
	miroPos[0][0] = numVec[2];
	miroPos[0][1] = numVec[3];

	//�̷� �� ���� x��ǥ y��ǥ ������ �о����
	miroPos[1][0] = numVec[4];
	miroPos[1][1] = numVec[5];

	//�̷� �б�
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
					//�Է��� 0��°�� �������� ���ڷ� �� �κ��� ������ �������� �̷� ��ü
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
	file.close(); //���� �ݱ�

	//miro�� temp�־ �̷� ���� ��
	miro = temp;

	numVec.clear();
	temp.clear();
}

void FindPath(int sx, int sy, int ex, int ey)
{	
	miro[sy][sx] = 'x'; //ó�� ��ġ�� �̹� �湮�Ѱ����� üŷ
	miro[ey][ex] = ' '; //������ -2

	stack <pair<int, int>> stk; //������ �� stack�� �־��
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

		bool isMove = false; //4���� �� ������ �����ߴ��� üũ
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

	std::cout << "���� ����: " << miroPos[0][0] << "," << miroPos[0][1]
		<< "���� ����: " << miroPos[1][0] << "," << miroPos[1][1] << std::endl;
	/*
	std::cout << "-----------�ʱ� �̷� ����--------------" << std::endl;
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

	std::cout << "---------------������ ��� �׸���---------------" << std::endl;
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
		std::cout << "�ּ� ������ �Ÿ�: " << pathCount << std::endl;
	}
	return 0;
}
