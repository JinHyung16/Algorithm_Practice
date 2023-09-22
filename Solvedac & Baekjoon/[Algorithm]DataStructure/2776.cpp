#include<iostream>
#include<set>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 �ϱ�� - �ڷᱸ�� �˰���
/// set�� �̿��� ������ �ذ��Ѵ�.
/// set�� ��ø1�� ������ �־�ΰ�, 2���� �Է¹��� �� 1���� ��� ã�ư���.
/// �� ������ 2�ʸ��� �ذ��ؾ� �ϹǷ� O(longN)�� �ɸ��� Ž���� �̿�����
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int T = 0; //�׽�Ʈ ���̽��� ���� T
	int N = 0, M = 0; //��ø 1�� ���� ���� ���� ���� N, ��ø 2�� ���� ���� ���� ���� M
	std::cin >> T;
	while ( T-- )
	{
		set<int> note;
		std::cin >> N;
		for ( int i = 0; i < N; i++ )
		{
			int input = 0;
			std::cin >> input;
			note.insert(input);
		}
		std::cin >> M;
		for ( int i = 0; i < M; i++ )
		{
			int input = 0;
			std::cin >> input;
			if ( note.find(input) != note.end())
			{
				std::cout << "1" << "\n";
			}
			else
			{
				std::cout << "0" << "\n";
			}
		}
	}
	return 0;
}