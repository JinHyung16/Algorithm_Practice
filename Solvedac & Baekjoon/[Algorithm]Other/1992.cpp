#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ����Ʈ�� - ���� ���� �˰���
/// 4���� �������� ������, �迭 ũ�� n/2�� �Ͽ� ������.
/// �ֳĸ� N�� 2�� �������� �־����� �����̴�.
/// ���� �Է��� ������� ���´�. ���� char�� �޾Ƽ� ������ �ذ�����
/// ó���� �̰� �𸣰� int�� �ߴٰ�, �Է��� ����� �ȵǾ ��Ȳ�ߴ�.
/// </summary>

using namespace std;

vector<vector<char>> map(64, vector<char>(64, 0));
vector<char> result;

void DivideMap(int x, int y, int n)
{
	char start = map[y][x];
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (start != map[i][j])
			{
				result.push_back('(');
				//��1,2,3,4��и� ������� �ݺ��Ѵ�.
				DivideMap(x, y, n / 2);
				DivideMap(x + (n / 2), y, n / 2);
				DivideMap(x, y + (n / 2), n / 2);
				DivideMap(x + (n / 2), y + (n / 2), n / 2);
				result.push_back(')');
				return;
			}
		}
	}
	result.push_back(start);
}

int main(void)
{
	FastIO;
	
	int N(0); //������ ũ�� N
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> map[i][j];
		}
	}

	DivideMap(0, 0, N);
	
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i];
	}
	std::cout << "\n";
	return 0;
}