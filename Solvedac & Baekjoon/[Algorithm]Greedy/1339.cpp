#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Gold4 �ܾ� ���� - Greedy �˰���
/// ���� ABC + BAC�� �Ѵٰ� �����غ���
/// ABC -> 100A + 10B + 1C
/// CAB -> 100C + 10A + 1B��
/// A�� ���� 110 B�� ���� 11B C�� 101C�� A > C > B ������� ���� ū ���� 9���� ä���ָ� �ȴ�.
/// �׷��Ƿ� 110A -> 110 * 9, 101C -> 101 * 8, 11B -> 11 * 7 
/// </summary>

int main(void)
{
	FastIO;

	int greedy[26] { 0, };
	int N = 0; //�ܾ��� ���� N
	cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		string input;
		cin >> input;
		int pow = 1;
		for ( int j = input.length() - 1; 0 <= j; j-- )
		{
			greedy[input[j] - 'A'] += pow;
			pow *= 10;
		}
	}

	sort(greedy, greedy + 26, greater<int>());

	int num = 9;
	int result = 0;
	for ( int i = 0; i < 26; i++ )
	{
		if ( greedy[i] == 0 )
		{
			break;
		}
		result += greedy[i] * num;
		num--;
	}
	cout << result << "\n";
	return 0;
}