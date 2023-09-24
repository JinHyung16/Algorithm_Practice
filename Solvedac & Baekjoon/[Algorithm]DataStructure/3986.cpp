#include<iostream>
#include<vector>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ���� �ܾ� - �ڷᱸ�� �˰���
/// AABB �Ǵ� ABBA �Ǵ� BAAB �̷� ������ ���;� ���� �ܾ��.
/// ���� stack�� �ܾ �ϳ��� �ִ´�.
/// stack�� top()�κа� �ܾ��� j��°�� ���ٸ� stack���� �����
/// stack�� ����� ������ ī������ ���ش�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //�ܾ��� �� N
	int goodCnt = 0; //���� �ܾ� ����
	std::cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		string input;
		std::cin >> input;
		stack<char> stk;
		for ( int j = 0; j < input.size(); j++ )
		{
			if ( !stk.empty() && stk.top() == input[j] )
			{
				stk.pop();
				continue;
			}
			stk.push(input[j]);
		}
		if ( stk.empty() )
		{
			goodCnt++;
		}

	}

	std::cout << goodCnt << "\n";
	return 0;
}