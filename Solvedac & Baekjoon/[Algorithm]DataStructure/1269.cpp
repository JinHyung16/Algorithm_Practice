#include<iostream>
#include<vector>
#include<set>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ��Ī ������ - �ڷ� ���� �˰���
/// set�� �ڵ����� �������� ���ĵȴ�.
/// �׷��Ƿ� A�� �Է¹ް�, B�� �Է¹��� �� 
/// if ( result.find(input) == result.end() )�� set�� ���� ������ end�� ��ȯ�ϹǷ�
/// ���� ���ٸ� ������� �ǹ̴�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int A = 0, B = 0; 
	int input = 0;
	std::cin >> A >> B;

	set<int> result;
	for ( int i = 0; i < A; i++ )
	{
		std::cin >> input;
		result.insert(input);
	}

	for ( int i = 0; i < B; i++ )
	{
		std::cin >> input;
		if ( result.find(input) == result.end() )
		{
			result.insert(input);
		}
		else
		{
			result.erase(input);
		}
	}

	std::cout << result.size() << "\n";
	return 0;
}