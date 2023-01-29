#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>

/// <summary>
/// Silver5 ȸ�翡 �ִ� ��� - Hash_Set �˰���
/// set�� �̿��ϸ� �ߺ��� �ڵ����� �������ִ� Ʈ����
/// ���������� ���ٴ� ������ ������Ű�µ� ����.
/// set�� �̿��� ���� ��½� rbegin(), rend()�� for���� ���¸� �� ����
/// </summary>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //�α׿� ��ϵ� ���� ����� �� N
	set<string> enterPersonSet;
	
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		string name, log;
		std::cin >> name >> log;

		if (log == "enter")
		{
			enterPersonSet.insert(name);
		}
		else
		{
			enterPersonSet.erase(name);
		}
	}

	for (auto s = enterPersonSet.rbegin(); s != enterPersonSet.rend(); s++)
	{
		std::cout << *s << "\n";
	}

	return 0;
}