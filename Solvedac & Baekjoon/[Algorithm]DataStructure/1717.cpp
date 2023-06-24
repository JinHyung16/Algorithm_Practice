#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 ������ ǥ�� - �ڷᱸ�� �˰���
/// 
/// �и����� ������ �̴� ���Ͽ� ���ε�� �Ҹ���.
/// ���Ͽ� ���ε�� '������ ã��'��� �ǹ̸� ������ �־� �̴� ���μ� ���� �˰��� �̶�� �Ҹ���. (1�ܿ� ����� ����)
/// �ٽ��� ������ �θ�(��ǥ��)���� �̿��� �̰͵鸸 ���ϰų� ��ġ�� ���̴�.
/// 1) �� ���ҿ� ���� �ʱ⿡�� ������ parent��. (�ʱ�ȭ)
/// 2) �� ������ �������� ������ �� ����� ���յ� ������ ��������, parent�� �ϳ��� ���� (union ����)
/// 3) � ���� b�� �־����� ��, �� ���Ұ� ���� ������ ��ȯ�Ѵ�. (find ����)
/// </summary>

using namespace std;

vector<int> parent; //�ڽ��� �θ��� ��ȣ�� ����

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

	int cmd = 0, a = 0, b = 0; //��ɾ�, �� ���� a, b
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