#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<map>

/// <summary>
/// Gold5 ��Ʈ ���� - Graph �˰���
/// �������� ������ �ϴ°� ���� ��ǥ
/// �ּ����� ��Ʈ�� ����°� �߿� -> ���� �պ��� �۰�, �ں��� ū�� �� ����
/// ó���� vecotr�̿�������, queue�� �ֱ� ��ȣ�ؼ� string���� ����
/// �迭 ��ü�� �־ ��� ���غ��� �������� ����
/// </summary>


using namespace std;

int n(0), k(0); //1���� n���� ��, ��������ϴ� k���� ��
string graph;
map<string, bool> visited;

int BFS(string s)
{
	//������������ ���ĵ� �迭 ����� �񱳿����� ���
	string ascendingOrder = s;
	std::sort(ascendingOrder.begin(), ascendingOrder.end());
	
	queue<pair<string, int>> q;
	q.push(make_pair(s, 0));
	visited[s] = true;
	
	while (!q.empty())
	{
		string now = q.front().first;
		int count = q.front().second;
		q.pop();

		if (now == ascendingOrder)
		{
			return count;
		}

		//�ٲܼ� �ִ� �κ� �� ã��
		for (int i = 0; i <= n - k; i++)
		{
			//�߰��κ� ���� �ٲٱ�
			string temp = now.substr(i, k);
			
			//������ ��Ű��
			reverse(temp.begin(), temp.end());

			//���ο� �迭 �����
			string next = now.substr(0, i);
			next += temp;

			//now�� ������ ����
			next += now.substr(i + k);
			//�ߺ� üũ
			if (!visited.count(next))
			{
				q.push(make_pair(next, count + 1));
				visited[next] = true;
			}
		}
	}

	//���� �������� ���� �� ������ -1 ���
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		graph += c;
	}

	std::cout << BFS(graph) << std::endl;
	return 0;
}