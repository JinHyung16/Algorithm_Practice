#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 ��ū�� - �ڷᱸ�� �˰���
/// ��ū���� Ai���� �����ʿ� �����鼭, Ai���� ū �� �߿��� ���� ���ʿ� �ִ� ���� �ǹ��Ѵ�.
/// 
/// 1) vector�� ������ �޴´�.
/// 2) vector�� �� �ں��� �Ųٷ� ��ū���� Ž���ذ��鼭 seqStk�� vector[i]���� �ִ´�.
/// 3) seqStk�� ������� ������ seqStk�� �������� ���鼭 seqStk�� top <= sequence[i]�� seqStk.pop, �ƴϸ� break�Ѵ�.
/// 4) seqStk�� empty�� resultStk.push(-1)�� �ƴ϶�� resultStk.push(seqStk.top())�� �Ѵ�.
/// 
/// �ݷ�) N=5, 1 8 5 7 9 �϶�
/// ���� -> 8 9 7 9 -1 / ���� -> 8 -1 7 9 -1 (��������)
/// 
/// 8�� ������ seqStk���� 5, 7, 9�� �׿������� seqStk.pop()�� 2�� ����Ǿ� seqStk.top()�� 9�� ���� break; ����ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //���� A�� ũ��
	std::cin >> N;

	vector<int> sequence(N, 0);
	stack<int> seqStk;
	stack<int> resultStk;
	
	for(int i = 0; i < N; i++)
	{
		std::cin >> sequence[i];
	}
	
	for(int i = N-1; 0 <= i; i--)
	{
		while(!seqStk.empty())
		{
			if(seqStk.top() <= sequence[i])
			{
				seqStk.pop();
			}
			else
			{
				break;
			}
		}

		if(seqStk.empty())
		{
			resultStk.push(-1);
		}
		else
		{
			resultStk.push(seqStk.top());
		}

		seqStk.push(sequence[i]);
	}

	while(!resultStk.empty())
	{
		std::cout << resultStk.top() << " ";
		resultStk.pop();
	}
	return 0;
}