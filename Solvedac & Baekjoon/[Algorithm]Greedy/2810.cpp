#include<iostream>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 ��Ȧ�� - Greedy �˰���
/// �¼� ������ �Է¹޴´�. �� �� L�� Ŀ�ü��� �ǹ��ϹǷ� Ŀ�ü��� ������ ����.
/// ��Ȧ�� ������ �ʱ� N+1�� �ʱ�ȭ �� ��, Ŀ�ü� ������ ���� ������ �޸��Ѵ�.
/// Ŀ�ü��� ���ٸ� ��Ȧ�� ���� = N
/// Ŀ�ü��� �ִٸ� ��Ȧ�� ���� = (N+1) - (couple/2)�� �Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	int N = 0; //�¼��� �� N
	string input; //�¼� ����

	std::cin >> N;
	std::cin >> input;

	int result = N + 1;
	int couple = 0;

	for ( int i = 0; i < input.size(); i++ )
	{
		if ( input[i] == 'L' )
		{
			couple++;
		}
	}

	if ( couple == 0 )
	{
		result = N;
	}
	else
	{
		result -= (couple / 2);
	}

	std::cout << result << "\n";
	return 0;
}