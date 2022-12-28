#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<set>

/// <summary>
/// Gold3 ��ȯ - Graph �˰���
/// BFS�� �̿��� �ذ�
/// �� �ڸ� �� �� �ƴ����� 1�� �ڸ��� 0�ΰ�� üũ
/// ������ queue�� pair�� ���� key,value�� ����������,
/// ������ ��� value�� ������� �ʾ� set�̿�
/// </summary>

using namespace std;

string n; // ���� N
int k(0); // ���� Ƚ�� k
int maxNum(0); // k�� ���� �� ���� �ִ� ����

bool CheckDigitsOFOne()
{
	int digitCnt(0);
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] > '0')
		{
			digitCnt++;
		}
	}

	if (digitCnt > 1)
	{
		return true;
	}
	return false;
}

void BFS()
{
	queue<string> q;
	q.push(n);

	for (int a = 0; a < k; a++)
	{
		int qSize = q.size();
		set<string> visited;

		for (int b = 0; b < qSize; b++)
		{
			string temp = q.front();
			q.pop();

			for (int i = 0; i < temp.size() - 1; i++)
			{
				for (int j = i + 1; j < temp.size(); j++)
				{
					if (i == 0 && temp[j] == '0')
					{
						continue;
					}

					std::swap(temp[i], temp[j]);
					if (visited.find(temp) == visited.end())
					{
						if (a == k - 1)
						{
							//������ k�� �������̶��
							int value = std::stoi(temp);
							maxNum = std::max(maxNum, value);
						}
						q.push(temp);
						visited.insert(temp);
					}
					std::swap(temp[i], temp[j]);
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> k;
	if (n.size() == 1)
	{
		//�� �ڸ� ���� ��� ������ �� ����
		std::cout << -1 << std::endl;
		return 0;
	}
	else if (n.size() == 2 && !CheckDigitsOFOne())
	{
		std::cout << -1 << std::endl;
		return 0;
	}

	BFS();

	std::cout << maxNum << std::endl;

	return 0;
}