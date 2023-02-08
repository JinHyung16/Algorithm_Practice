#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 �ٹ�ȣ - ���ڿ� �˰���
/// ������ �����ؼ� �Է��� �ޱ����� getline�� ����ߴ�.
/// ������ �ټ��� �Է¹��� �� ���ڿ��� ������ cin�� ���๮�ڰ� ���־� ��½� ó���� �������θ� ���´�.
/// �׷��Ƿ� ignore�� ���� cin ���۸� ���� �Է� �ް� �� �� clear�� cin�� ������Ʈ�� �����ش�.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	int N(0); //���� �� N
	std::cin >> N;

	vector<string> stringVec;

	std::cin.ignore(); //cin���� ���๮�� �����
	while (N--)
	{
		string input;
		std::getline(cin, input);
		std::cin.clear();
		stringVec.push_back(input);
	}

	for (int i = 0; i < stringVec.size(); i++)
	{
		std::cout << i + 1 << ". " << stringVec[i] << "\n";
	}
	return 0;
}