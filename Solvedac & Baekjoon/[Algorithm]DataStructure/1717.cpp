#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 집합의 표현 - 자료구조 알고리즘
/// 
/// 분리집합 문제로 이는 유니온 파인드라 불린다.
/// 유니온 파인드는 '합집합 찾기'라는 의미를 가지고 있어 이는 서로소 집합 알고리즘 이라고도 불린다. (1외에 공약수 없음)
/// 핵심은 원소의 부모값(대표값)만을 이용해 이것들만 비교하거나 합치는 것이다.
/// 1) 각 원소에 대해 초기에는 본인이 parent다. (초기화)
/// 2) 두 원소의 공통점이 같으면 두 사람이 포합된 집합이 합쳐지고, parent는 하나로 고정 (union 연산)
/// 3) 어떤 원소 b가 주어졌을 때, 이 원소가 속한 집합을 반환한다. (find 연산)
/// </summary>

using namespace std;

vector<int> parent; //자신의 부모의 번호를 저장

int Find(int num)
{
	if(parent[num] == num)
	{
		return num;
	}
	parent[num] = Find(parent[num]);
	return parent[num];
}

void Union(int a, int b)
{
	int parentA = Find(a);
	int parentB = Find(b);
	if(parentA == parentB)
	{
		return;
	}
	parent[parentB] = parentA;
}

int main(void)
{
	FastIO;

	int n = 0, m = 0;
	std::cin >> n >> m;
	for(int i = 0; i <= n; i++)
	{
		parent.push_back(i);
	}

	int cmd = 0, a = 0, b = 0; //명령어, 두 원소 a, b
	for(int  i = 0; i < m; i++)
	{
		std::cin >> cmd >> a >> b;
		if(cmd == 0)
		{
			Union(a, b);
		}
		else
		{
			if(Find(a) == Find(b))
			{
				std::cout << "YES" << "\n";
			}
			else
			{
				std::cout << "NO" << "\n";
			}
		}
	}
	return 0;
}