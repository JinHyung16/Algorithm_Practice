#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 �Ųٷ� ������ - ���Ʈ���� �˰���
/// �������� string���� ��ȯ�Ͽ� ���̸�ŭ �ڿ������� for���� ����.
/// �׷��� ������ ��Ų ���� stoi�� ���� int�� ��ȯ�� �� vector�� �ְ�
/// �������� ������������ sort��Ų��.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, K = 0;
	std::cin >> N >> K;

	vector<int> result;
	for ( int i = 1; i <= K; i++ )
	{
		string multi = std::to_string(N * i);
		string temp;
		for ( int j = multi.length() - 1; 0 <= j; j-- )
		{
			temp += multi[j];
		}
		int multi_int = std::stoi(temp);
		result.push_back(multi_int);
	}

	std::sort(result.rbegin(), result.rend());
	std::cout << result[0] << "\n";
	return 0;
}