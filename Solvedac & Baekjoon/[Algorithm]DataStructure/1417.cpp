#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 ��ȸ�ǿ� ���� - �ڷᱸ�� �˰���
/// ��ȣ 1���� �ټ��̴� 1���� �����ϰ� ������ ��� �� ū ��ǥ���� ���� �ִ� ����� ��ǥ�� �����´�.
/// pq�� �ټ��� ���� ū ��ǥ������ �ְ�, ���⼭ �ϳ��� ���� ���� �ٿ����鼭 �ټ��̺��� ���� �� ���� ������.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0;
	int temp = 0; //�ټ��� ��ǥ��
	int result = 0;
	priority_queue<int> pq;
	std::cin >> N;

	for ( int i = 0; i < N; i++ )
	{
		int input = 0;
		std::cin >> input;
		if ( i == 0 )
			temp = input;
		if ( temp <= input && i != 0 )
			pq.push(input);
	}
	while ( !pq.empty() && temp <= pq.top() )
	{
		int top = pq.top();
		pq.pop();
		top--;
		result++;
		temp++;
		pq.push(top);
	}

	std::cout << result << "\n";
	return 0;
}