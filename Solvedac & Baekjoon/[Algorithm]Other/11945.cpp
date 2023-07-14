#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 �߰ſ� �ؾ - ���ڿ� �˰���
/// string���� �Է¹޾� vector<string>�� �ִ´�.
/// �� N�� �Է¹����鼭 0��° �ٿ� string���� �Է¹����� vector�� �����鼭 N��° �ٱ��� �� string���� ���ְ� �ȴ�.
/// �� �Է¹ް� for i to N ���鼭 reverse(vector[i].begin(), vector[i].end())�� �����Ͽ� �� ���� string���� ����� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	int N = 0, M = 0; //N���� �ٰ� M���� ��
	vector<string> result;
	string input;
	std::cin >> N >> M;
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> input;
		result.push_back(input);
	}

	for ( int i = 0; i < N; i++ )
	{
		reverse(result[i].begin(), result[i].end());
		std::cout << result[i] << "\n";
	}
	return 0;
}