#include<iostream>
#include<vector>
#include<map>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ��й�ȣ ã�� - �ڷᱸ�� �˰���
/// �ߺ��� ������� �ʴ� (key,value) ������ �̷��� Ʈ�� map�� �̿��ߴ�.
/// c++ map�� �˻�, ����, ������ O(logN)�̴�. �⺻������ �������� �����̴�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0), M(0); //����� ����Ʈ �ּ��� �� N, ��й�ȣ�� ã������ ����Ʈ �ּ��� �� M
	map<string, string> memoNote;
	std::cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		string site, password;
		std::cin >> site >> password;
		memoNote.insert(make_pair(site, password));
	}

	for (int i = 0; i < M; i++)
	{
		string findSite;
		std::cin >> findSite;
		std::cout << memoNote[findSite] << "\n";
	}
	return 0;
}