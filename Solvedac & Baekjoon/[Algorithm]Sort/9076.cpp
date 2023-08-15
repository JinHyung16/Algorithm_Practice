#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 ���� ���� - ���� �˰���
/// sort�Ͽ� vector�� index 1���� 3���� ���Ѵ�. (�ֳĸ� 0������ �����̴�)
/// �� �� 4�̻��̸� KIN ����� continue�� ������ ������ ���� �Է��� �޴´�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int T = 0; //�׽�Ʈ ���̽� ����
	std::cin >> T;

	while ( T-- )
	{
		vector<int> scores;
		for ( int i = 0; i < 5; i++ )
		{
			int input;
			std::cin >> input;
			scores.push_back(input);
		}

		std::sort(scores.begin(), scores.end());
		if ( 4 <= scores[3] - scores[1] )
		{
			std::cout << "KIN" << "\n";
			continue;
		}
		std::cout << scores[1] + scores[2] + scores[3] << "\n";
	}
	return 0;
}