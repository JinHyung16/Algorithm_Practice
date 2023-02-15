#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 ���� �ڸ��� ã�ƶ� - ���ڿ� �˰���
/// string���� ���� ���پ�(�����ǹ�) �Է¹޾� char Ÿ���� vector�� �ִ´�.
/// �̶� �����鼭 ���η� ���� �� �ִ� ������ ���� ã�ư��°� ����Ʈ
/// �� �� ���� �� �־����� ���η� ���� �� �ִ� ������ ã�ư���.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //���� ũ�� N
	string roomInput; //��
	int rowCnt(0), colCnt(0), emptyCnt(0);
	vector<vector<char>> room(101, vector<char>(101, ' '));

	std::cin >> N;
	//�ʱ� �� ���¸� ���پ� �Է¹޴´�
	//�Է� �����鼭 ���η� ���� �� �ִ� ������ ���� ã�ư���.
	for (int i = 0; i < N; i++)
	{
		std::cin >> roomInput;
		emptyCnt = 0;
		for (int j = 0; j < roomInput.size(); j++)
		{
			room[i][j] = roomInput[j];
			if (room[i][j] == '.')
			{
				//�� �����̸�
				emptyCnt++;
			}
			else
			{
				//room[i][j] == 'X' �� ���� �����ٸ�
				if (2 <= emptyCnt)
				{
					colCnt++;
				}
				emptyCnt = 0;
			}
		}
		//���� ������ ��
		if (2 <= emptyCnt)
		{	
			colCnt++;
		}
	}

	//���η� ���� �� �ִ� ������ ã�´�.
	for (int i = 0; i < N; i++) {
		emptyCnt = 0;
		for (int j = 0; j < N; j++) {
			if (room[j][i] == '.')
			{
				emptyCnt++;
			}
			else 
			{
				//room[i][j] == 'X' �� ���� �����ٸ�
				if (2 <= emptyCnt)
				{
					rowCnt++;
				}
				emptyCnt = 0;
			}
		}
		//���� ������ ��
		if (2 <= emptyCnt)
		{
			rowCnt++;
		}
	}

	cout << colCnt << " " << rowCnt << "\n";

	return 0;
}