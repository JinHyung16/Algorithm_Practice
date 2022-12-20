#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Gold4 거짓말 - Graph 알고리즘
/// 처음 DFS로 푸는데 문제는 같은 그룹인지 체크하는게 부족했다
/// 이에 파티에 참석한 인원끼리 같은 그룹인것을 표현해주자
/// 또한, trueKnowCount가 0인데 for문으로 입력 받으면 콘솔에서 안넘어가니
/// while문으로 바꿔서 입력을 처리해주는 습관도 가져보자
/// </summary>


using namespace std;


int n, m; //사람의 수 n, 파티의 수 m
int trueKnowCount; //진실을 아는 사람의 수
vector<int> truePeople; //0이상 50이하의 진실을 아는 사람들
vector<vector<int>> partyPeople; //1이상 50이하의 party 참여한 사람들
bool SameGroup[52][52]; //같은 그룹의 사람들 묶기
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