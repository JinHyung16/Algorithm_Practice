#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 ����� - DataStructure �˰���
/// stack�� ���븦 �Է¹޾� ���´�.
/// �������� �����ʿ��� ���ٰ� ������, �̴� �迭�� ����� ��
/// �迭�� �� ������ 0��° index�̹Ƿ� �����ʿ��� �� ���� �������� �迭 �� �ڿ������� ������ �Ѵ�.
/// ���� stack�� �̿��� LIFO ������ Ȱ���Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //����� N��
	stack<int> stk;

	int stickCnt = 1;

	std::cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int height = 0;
		std::cin >> height;
		stk.push(height);
	}
	
	int maxHeight = stk.top();
	stk.pop();

	while(!stk.empty())
	{
		if( maxHeight < stk.top())
		{
			maxHeight = stk.top();
			stickCnt += 1;
		}
		stk.pop();
	}

	std::cout << stickCnt << "\n";
	return 0;
}