#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 ����� �ʴ� - �׸��� �˰���
/// �ʴ� �ؾ��ϴ� ������ ���� ã������, �Է����� ���� ������ �������� �ϰ�,
/// result���� result�� �迭[i] + day�� �� ū ���� �׻� �޴´�.
/// day�� i���� �����Ҷ����� ������Ų��.
/// �� �� �������� result�� ����ϸ� �ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0; //������ �� N
	std::cin >> N;
	vector<int> trees;
	for ( int i = 0; i < N; i++ )
	{
		int t = 0;
		std::cin >> t;
		trees.push_back(t);
	}

	int result = -1, day = 1;
	std::sort(trees.rbegin(), trees.rend());
	for ( int i = 0; i < trees.size(); i++ )
	{
		result = std::max(result, trees[i] + day);
		day++;
	}
	result++;

	std::cout << result << "\n";

	return 0;
}