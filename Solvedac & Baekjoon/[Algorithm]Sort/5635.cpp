#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 ���� - ���� �˰���
/// vector�� pair�� ���� �ִ� 2�������ۿ� �� �ִ´�.
/// ���� vector<pair<pair<int,in>, pair<int, string>>>�� ���� ����,��,��, �̸� ������ �޴´�.
/// �� �̷� ������ �����ϳĸ� ��->��->�� ������ sort�ϱ� ���ؼ���.
/// 
/// �������� �Է� ������ �̸�, ��, ��, �⵵�� vector�� ������ �� �����ؼ� ����
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int n = 0; //�� �л��� �� n
	std::cin >> n;
	vector<pair<pair<int, int>, pair<int, string>>> students(n);

	for ( int i = 0; i < n; i++ )
	{
		std::cin >> students[i].second.second >> students[i].second.first >> students[i].first.second >> students[i].first.first;
	}

	std::sort(students.begin(), students.end());

	std::cout << students[n - 1].second.second << "\n" << students[0].second.second << "\n";
	return 0;
}