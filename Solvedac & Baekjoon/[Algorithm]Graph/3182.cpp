#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 �ѵ��̴� ���ΰ� �ϱ� �Ⱦ�! - Graph �˰���
/// �ϳ� �̻��� ������ �ִ� ��� ��ȣ�� ���� ���踦 ����ؾ� �ϹǷ�, ��ȣ�� ���� ������ Ž���� �õ��Ѵ�.
/// </summary>

using namespace std;

int N = 0; //������� ��ȣ N
vector<int> person(1001, 0);
vector<bool>visited(1001, false);

void ResetVisit()
{
	for ( int i = 0; i < visited.size(); i++ )
	{
		if ( visited[i] )
		{
			visited[i] = false;
		}
	}
}

int main(void)
{
	FastIO;

	std::cin >> N;

	for ( int i = 0; i < N; i++ )
	{
		int input = 0;
		std::cin >> input;
		input -= 1;
		person[i] = input;
	}

	int meet = 0;
	int minPerson = 0;
	for ( int i = 0; i < N; i++ )
	{
		ResetVisit();
		int cur = i;
		int cnt = 0;
		while ( !visited[cur] )
		{
			visited[cur] = true;
			cur = person[cur];
			cnt += 1;
		}

		if ( meet < cnt )
		{
			meet = cnt;
			minPerson = i;
		}
	}

	std::cout << minPerson + 1 << "\n";

	return 0;
}