#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 �踷��� - �ڷᱸ�� �˰���
/// ������ �̿��Ͽ� ������ �ذ��Ѵ�. �� �� ���� ��ȣ�� ���� ���ÿ� �ִ���, ���ÿ��� ������ �����Ѵ�.
/// �켱 ��ü �߷��� ������ ���� ���� stack�� �� ���̿� ������ �̸� ������ �μ� stickCount ������ ����.
/// 
/// for i to string.size() ���鼭
/// 1) i��°�� (�� ���� ���, i-1��°�� )�� i��°�� ������ �������� �ǹ��ϹǷ� ���ÿ� push
/// 2) i��°�� (�� ���� ���, i-1��°�� (�� ���� �����̰ų� �������� �� ������ �켱 ���ÿ� push
/// 3) i��°�� )�� ���� ���, i-1��°�� (�� �������� �ǹ��ϹǷ� ���ÿ��� pop�ϰ� stickCount += stack.size()
/// 4) i��°�� )�� ���� ���, i-1��°�� )�� ���� ���� �ǹ��ϹǷ� ���ÿ��� pop�ϰ� stickCount ++
/// �� �� �����ϰ� �� �� stickCount�� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	string input;
	stack<char> stk;
	int stickCount = 0;

	std::cin >> input;
	for(int i = 0; i < input.size(); i++)
	{
		if(input[i] == '(')
		{
			stk.push(input[i]);
		}
		else
		{
			if(input[i-1] == '(')
			{
				stk.pop();
				stickCount += stk.size();
			}
			else
			{
				stk.pop();
				stickCount++;
			}
		}
	}

	std::cout << stickCount << "\n";

	return 0;
}