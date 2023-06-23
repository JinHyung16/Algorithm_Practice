#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ���ڿ� ���� - �ڷᱸ�� �˰���
/// 1) N���� ���ڿ��� �ߺ����� �Է¹ް�,
/// 2) �Է¹����� ���� M���� �Է¹��� �� ���� �ߺ��ȴٸ� �̶� ī������ ���ָ� �� ��� �ִ��� �� �� �ִ�.
/// 
/// c++�� STL�� map�� ����ϸ� �ȴ�.
/// map�� pair<key, value> ������ insert�Ѵ�.
/// map<key, value>�� �̷��� �����Ʈ���� �˻�, ����, ������ O(log n) �ɸ���.
/// map�� �⺻������ �������� �����̴�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0, M = 0; //���տ� �ִ� N���� ���ڿ�, �˻��ؾ��ϴ� M���� ���ڿ�
	std::cin >> N >> M;

	string input;
	int result = 0;
	map<string, bool> set;

	for(int i = 0; i < N; i++)
	{
		std::cin >> input;
		set.insert(pair<string, bool>(input, true));
	}

	for(int i = 0; i < M; i++)
	{
		std::cin >> input;
		if(set[input] == true)
		{
			result += 1;
		}
	}
	std::cout << result << "\n";
	return 0;
}