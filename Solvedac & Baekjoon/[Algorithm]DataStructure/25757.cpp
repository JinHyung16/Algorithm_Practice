#include<iostream>
#include<vector>
#include<set>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 �ӽ��� �Բ��ϴ� �̴ϰ��� - �ڷᱸ�� �˰���
/// set�� ���� �ߺ��� �����ϸ� player���� �Է� �޴´�.
/// �׸��� game�� ������ ���� ����ϴµ� Y�� �Է¹��� �ο��� ��, F�� / 2, O�� / 3�� �Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0; //��û Ƚ�� N
	char game; //���� ������ ����
	set<string> player;
	std::cin >> N >> game;
	for ( int i = 0; i < N; i++ )
	{
		string input;
		std::cin >> input;
		player.insert(input);
	}
	if ( game == 'Y' )
	{
		std::cout << player.size();
	}
	else if ( game == 'F' )
	{
		std::cout << player.size() / 2;
	}
	else if ( game == 'O' )
	{
		std::cout << player.size() / 3;
	}
	return 0;
}