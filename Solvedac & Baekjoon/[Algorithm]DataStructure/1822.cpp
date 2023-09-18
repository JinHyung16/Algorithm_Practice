#include<iostream>
#include<vector>
#include<set>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ������ - �ڷ� ���� �˰���
/// set�� �̿��� A�� �Է¹޴´�.
/// �׸��� B�� �Է¹��� �� A�� ���ٸ� �н�, ������ �ش� ���� �����.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int nA = 0, nB = 0; //A���� ���� ����, B���� ���� ����
	std::cin >> nA >> nB;
	int input = 0;

	set<int> duplication;
	
	for ( int i = 0; i < nA; i++ )
	{
		std::cin >> input;
		duplication.insert(input);
	}

	for ( int i = 0; i < nB; i++ )
	{
		std::cin >> input;
		if ( duplication.find(input) == duplication.end() )
		{
			continue;
		}
		else
		{
			duplication.erase(input);
		}
	}

	std::cout << duplication.size() << "\n";

	for ( auto d : duplication )
	{
		std::cout << d << " ";
	}
	std::cout << "\n";

	return 0;
}