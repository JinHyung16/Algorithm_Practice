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
vector<vector<int>> miroPos(2, vector<int>(2, 0)); //miro�� �־��� ���ǵ� ����

//(1,1)���� ���� down->left->up->right ������ ���캻��
vector<int> dx = { 0, 1, 0, -1 };
vector<int> dy = { 1, 0, -1, 0 };

stack <pair<int, int>> pathStk; //������ �� stack�� �־��

void FileInput()
{
	//ó�� ������ ���� ���ڸ� �о �����صд�

	ifstream file("miro.txt");
	vector<int> numVec; //index 0~1�� row, col size�ǹ� index 2~3�� ������ x,y ��ǥ�� 4~5�� �������� x,y ��ǥ �ǹ�
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
	file.close(); //���� �ݱ�

	//miro�� temp�־ �̷� ���� ��
	miro = temp;

	numVec.clear();
	temp.clear();
}

void FindPath(const vector<vector<char>>& m, int sx, int sy, int ex, int ey)
{
	vector<vector<char>> maze = m;
	maze[sy][sx] = 'S'; //ó�� ��ġ�� �̹� �湮�Ѱ����� üŷ
	maze[ey][ex] = 'E'; //������

	//stack <pair<int, int>> pathStk; //������ �� stack�� �־��
	pathStk.push(make_pair(sx, sy));

	int curX = pathStk.top().first;
	int curY = pathStk.top().second;

	while (true)
	{
		maze[curY][curX] = 'x';

		if (curY == ey && curX == ex)
		{
			maze[curY][curX] = 'x';
			//�����ߴٸ�
			std::cout << "�̷� ����" << std::endl;
			break;
		}

		bool isMove = false; //4���� �� ������ �����ߴ��� üũ
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

	std::cout << "Row Size:" << Y << " Col Size:" << X << "\n" << "���� ����:" << miroPos[0][0] << "," << miroPos[0][1]
		<< "���� ����:" << miroPos[1][0] << "," << miroPos[1][1] << std::endl;

	std::cout << "-----------�ʱ� �̷� ����--------------" << std::endl;
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

	std::cout << "---------------�̷� ���� ��---------------" << std::endl;

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
		std::cout << "�ּ� ������ �Ÿ�: " << pathCount << std::endl;
	}
	return 0;
}
