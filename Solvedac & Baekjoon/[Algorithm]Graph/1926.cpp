#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 �׸� - Graph �˰���
/// DFS�� �̿��� Ǯ�̴�.
/// dfs�� �� �б����� ���� ������ �������Ѵ�.
/// 1) �ʱ� �Է¹��� n, m�� ���� 2�� for���� ���鼭 i, j��°�� ���� DFS�� �����ϸ鼭 �׸��� �� ������ ã�´�.
/// 2) DFS������, �ش� i,j ��°���� ������ �׸��� �ִ��� üũ�ϸ鼭 ������ ���̸� ã�´�.
/// 
/// �̷��� 2���� ������ �������� �������� �׸��� �������� üũ�ϰ�, �̿� ���� ����Ѵ�.
/// </summary>

using namespace std;

int n = 0, m = 0; //��ȭ�� ���� n, ���� m
vector<vector<int>> paper(501, vector<int>(501, 0));
vector<vector<bool>> visited(501, vector<bool>(501, false));
vector<int> drawings; //�ϼ��� �׸����� ��Ƶ� �迭
int drawSize = 1;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void DFS(int x, int y)
{
	visited[y][x] = true;

	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || m < nx || ny < 0 || n < ny)
		{
			continue;
		}
		if(!visited[ny][nx] && paper[ny][nx] == 1)
		{
			visited[ny][nx] = true;
			drawSize ++;
			DFS(nx, ny);
		}
	}
}

int main(void)
{
	FastIO;

	std::cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			std::cin >> paper[i][j];
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(paper[i][j] == 1 && !visited[i][j])
			{
				DFS(j, i);
				drawings.push_back(drawSize);
				drawSize = 1;
			}
		}
	}

	std::sort(drawings.rbegin(), drawings.rend());

	int cnt = drawings.size() ? drawings.size() : 0; //drawings.size()�� ������ �װ�, �ƴϸ� 0���

	std::cout << cnt << "\n";

	//�׸��� ���ٸ� 0, ������ ���� ū ���� ���
	if( cnt == 0)
	{
		std::cout << 0 << "\n";	
	}
	else
	{
		std::cout << drawings[0] << "\n";
	}
	
	return 0;
}