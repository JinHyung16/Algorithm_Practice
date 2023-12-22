#include<iostream>
#include<vector>
#include<set>
#include<map>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Standard 트리인가? - 트리 알고리즘
/// 트리의 성질 2가지를 만족해야 한다.
/// 1) 트리 정점의 개수 =  간선의 개수 + 1
/// 2) 트리는 사이클이 없어야 한다.
/// 이때 간선이 0개여도 트리는 될 수 있으니 이 점도 유의하자
/// </summary>


int main(void)
{
	FastIO;

	vector<pair<int, int>> edge;
	set<int> node;
	map<int, int> indegree;

	int treeCase = 1;

	int u = 0, v = 0; // 노드 u에서 노드 v로 가는 간선
	while (true)
	{
		cin >> u >> v;

		if (u == -1 && v == -1) break;
		if (u == 0 && v == 0)
		{
			if (edge.size() + 1 == node.size() || edge.size() == 0)
			{
				bool isTree = true;
				int rootCount = 0;
				for (auto it : indegree)
				{
					if (it.second == 0) rootCount++;
					if (1 < rootCount || 1 < it.second)
					{
						isTree = false;
						break;
					}
				}
				if (isTree)
					cout << "Case " << treeCase << " is a tree." << "\n";
				else
					cout << "Case " << treeCase << " is not a tree." << "\n";
			}
			else
				cout << "Case " << treeCase << " is not a tree." << "\n";
			treeCase++;
			node.clear();
			edge.clear();
			indegree.clear();
		}
		else
		{
			node.insert(u);
			node.insert(v);
			edge.push_back(make_pair(u, v));
			indegree[v]++;
		}
	}
	return 0;
}