#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 ���� �� ���� ��..? - ���� �˰���
/// ũ�Ⱑ 31�� �迭�� �����.
/// �ֳĸ� �л����� 30������ index ����� 1������ �ؾ� �ϱ� �����̴�.
/// �л� ��ȣ�� �Է� ������ �ش� ��ȣ�� index�� �ϴ� �迭�� ���� 1�� �ٲ۴�.
/// for i=1 to 30�� ���� �迭�� index�� ���� 0�� �� i�� ����Ѵ�.
/// </summary>


int main(void)
{
	FastIO;

	vector<int> students(31, 0);

	int input = 0;
	for ( int i = 0; i < 28; i++ )
	{
		cin >> input;
		students[input] = 1;
	}

	for ( int i = 1; i <= 30; i++ )
	{
		if ( students[i] == 1 )
			continue;
		else
			cout << i << "\n";
	}
	return 0;
}