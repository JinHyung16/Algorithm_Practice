#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 ��Ʈ�ι̳� - ���Ʈ���� �˰���
/// DFS�� ��͸� �̿��� �ذ�
/// ���� ����� �����ϰ� ������ ȸ����Ű�ų� ��Ī�� �������� �ƹ��� ������ depth�� 3�̴�.
/// ���� T�ڸ� ���� ��, ��, ��, �̷� ���� �����ְ� ������ �������� depth�� 3�϶� ���� ������ �����ش�.
/// 
/// �Ǹ���� �������� �� ������ ȸ������ �����ϵ� �̶� ������ [0]�� �������� ȸ�����״ٰ� �����Ͽ� ��ǥ �����Ѵ�.
///    [3]
/// [0][1][2] ��翡�� [0]�� �׻� ��ǥ�� (y,x)��
/// 
/// �̸�翡�� �� ȸ����Ų ��� ��ǥ �����Ҷ� �Ʒ��� �����Ѵ�. N�� ����, M�� ���ζ�� �����Ͽ� N=y�� M=x�� �����ȴ�.
/// [0][1][2]  �� ����̸� [0]�� (y,x)�̹Ƿ� [3]�� y-1�̰�, [2]�� x+2��. �� ����� ������ 0<=y-1 && x+2 < M ���� �����ϴ�
///    [3]     ���� �̶� maxSum�� ���ϱ� ���ؼ� [0]+[1]+[2]+[3]�� �����Ͽ� [y][x] + [y][x+1] + [y][x+2] + [y-1][x+1]�Ѵ�.
/// 
/// �ø���� ������ ���� ������, ������� ������ ���� ������ �ǹǷ� �̿� ���� (y,x)�� ã��
///    [2]                   [2]
/// [3][1]                   [1][3]
///    [0]                   [0]
/// </summary>

using namespace std;

int N(0), M(0); //������ ũ�� N*M
vector<vector<int>> paper(501, vector<int>(501, 0));
vector<vector<bool>> visited(501, vector<bool>(501, false));
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int maxSum = -98765;


void TShape(int x, int y)
{
	//�� ���
	if (x + 2 < M && 0 <= y - 1)
	{
		maxSum = std::max(maxSum, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y - 1][x + 1]);
	}

	//�� ���
	if (x + 2 < M && y + 1 < N)
	{
		maxSum = std::max(maxSum, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y + 1][x + 1]);
	}

	//�� ���
	if (0 <= x - 1 && y + 2 < N)
	{
		maxSum = std::max(maxSum, paper[y][x] + paper[y + 1][x] + paper[y + 2][x] + paper[y + 1][x - 1]);
	}

	//�� ���
	if (x + 1 < M && y + 2 < N)
	{
		maxSum = std::max(maxSum, paper[y][x] + paper[y + 1][x] + paper[y + 2][x] + paper[y + 1][x + 1]);
	}
}

void Tetris(int x, int y, int depth, int sum)
{
	if (depth == 3)
	{
		maxSum = std::max(maxSum, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (0 <= nextX && nextX < M && 0 <= nextY && nextY < N)
		{
			if (!visited[nextY][nextX])
			{
				visited[nextY][nextX] = true;
				Tetris(nextX, nextY, depth + 1, sum + paper[nextY][nextX]);
				visited[nextY][nextX] = false;
			}
		}
	}
}
int main(void)
{
	FastIO;
	
	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> paper[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			TShape(j, i);
			visited[i][j] = true;
			Tetris(j, i, 0, paper[i][j]);
			visited[i][j] = false;
		}
	}

	std::cout << maxSum << "\n";
	return 0;
}