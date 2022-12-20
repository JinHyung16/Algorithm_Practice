#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Gold4 ������ - Graph �˰���
/// ó�� DFS�� Ǫ�µ� ������ ���� �׷����� üũ�ϴ°� �����ߴ�
/// �̿� ��Ƽ�� ������ �ο����� ���� �׷��ΰ��� ǥ��������
/// ����, trueKnowCount�� 0�ε� for������ �Է� ������ �ֿܼ��� �ȳѾ��
/// while������ �ٲ㼭 �Է��� ó�����ִ� ������ ��������
/// </summary>


using namespace std;


int n, m; //����� �� n, ��Ƽ�� �� m
int trueKnowCount; //������ �ƴ� ����� ��
vector<int> truePeople; //0�̻� 50������ ������ �ƴ� �����
vector<vector<int>> partyPeople; //1�̻� 50������ party ������ �����
bool SameGroup[52][52]; //���� �׷��� ����� ����
bool visited[52];

void BFS(int start)
{
	queue<int> q;
	q.push(start);

	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (SameGroup[cur][i])
			{
				if (visited[i])
				{
					continue;
				}
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> m;
	std::cin >> trueKnowCount;

	int input;
	while (trueKnowCount--)
	{
		std::cin >> input;
		truePeople.push_back(input);
	}

	int member;
	for (int i = 0; i < m; i++)
	{
		std::cin >> member;

		vector<int> memberVec;
		int temp;
		while (member--)
		{
			std::cin >> temp;
			memberVec.push_back(temp);
		}

		partyPeople.push_back(memberVec);

		for (int a = 0; a < memberVec.size() - 1; a++)
		{
			for (int b = a + 1; b < memberVec.size(); b++)
			{
				SameGroup[memberVec[a]][memberVec[b]] = true;
				SameGroup[memberVec[b]][memberVec[a]] = true;
			}
		}
	}

	for (auto t : truePeople)
	{
		BFS(t);
	}

	int canTalkCount = 0;
	for (auto p : partyPeople)
	{
		bool isCheck = false;
		for (auto pp : p)
		{
			if (visited[pp])
			{
				isCheck = true;
				break;
			}
		}

		if (!isCheck)
		{
			canTalkCount++;
		}
	}

	std::cout << canTalkCount << std::endl;
	return 0;
}