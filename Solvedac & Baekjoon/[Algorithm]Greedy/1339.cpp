#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Gold4 단어 수학 - Greedy 알고리즘
/// 만약 ABC + BAC를 한다고 가정해보자
/// ABC -> 100A + 10B + 1C
/// CAB -> 100C + 10A + 1B다
/// A의 합은 110 B의 합은 11B C의 101C로 A > C > B 순서대로 가장 큰 숫자 9부터 채워주면 된다.
/// 그러므로 110A -> 110 * 9, 101C -> 101 * 8, 11B -> 11 * 7 
/// </summary>

int main(void)
{
	FastIO;

	int greedy[26] { 0, };
	int N = 0; //단어의 개수 N
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