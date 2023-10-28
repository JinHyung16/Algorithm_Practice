#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze2 ���̾� - ���� �˰���
/// ������ ������ Ǯ���� ��, �� ���ĺ��� �޾� ���ڸ� ����ϴ� �����̿���.
/// �̸� ���� �� �����ϰ� �迭�� �ٲ㺻��.
/// �빮�� A�� ���� 0���� �Ϸ��� �ƽ�ũ �ڵ�� 65��° �̹Ƿ� A[i] - 65���Ѵ�.
/// </summary>


int alpha[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };

int main(void)
{
	FastIO;
	
	string input;
	int time = 0;

	cin >> input;
	for ( int i = 0; i < input.length(); i++ )
	{
		time += alpha[input[i] - 65];
	}

	cout << time << "\n";
	return 0;
}