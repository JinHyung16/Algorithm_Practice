#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 ��ŸƮ��ũ - Graph �˰���
/// ���� U�� D�� ��Ƶ� �迭�� �����Ѵ�.
/// �̶� D�� �Ʒ��� �������°� �ǹ��ϴ� �迭���� �������� ���� ������ -1�� ���Ѵ�.
/// �� �� BFS�� ���� U �Ǵ� V �� 2�� for���� ���� �����̸鼭
/// moveCnt�迭�� ���� �������� �̵��� Ƚ���� ���� �������� �̵��� Ƚ�� + 1�Ͽ� �����Ѵ�.
/// </summary>

int moveDir[2];
vector<bool> visited;
vector<int> moveCnt;

void BFS(int start, int maxFloor)
{
	queue<int> q;
	visited[start] = true;
	q.push(start);

	while ( !q.empty() )
	{
		int cur = q.front();
		q.pop();

		for ( int i = 0; i < 2; i++ )
		{
			int next = cur + moveDir[i];
			if ( 0 < next && next <= maxFloor )
			{
				if ( !visited[next] )
				{
					visited[next] = true;
					q.push(next);
					moveCnt[next] = moveCnt[cur] + 1;
				}
			}
		}
	}
}

int main(void)
{
	FastIO;

	int F = 0, S = 0, G = 0, U = 0, D = 0; //F�� �ǹ�, ��ǥ ��ġ G��, U��ư(��), D��ư(�Ʒ�), ���� �ִ� �� S��
	cin >> F >> S >> G >> U >> D;

	visited.resize(F + 1, false);
	moveCnt.resize(F + 1, 0);

	moveDir[0] = U;
	moveDir[1] = D * -1; //�Ʒ��� ��������
	
	BFS(S, F);

	if ( visited[G] )
		cout << moveCnt[G] << "\n";
	else
		cout << "use the stairs" << "\n";
	return 0;
}